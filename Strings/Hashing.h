/**
 * Description: Various self-explanatory methods for string hashing.
 * Use on Codeforces, which lacks 64-bit support and where solutions can be hacked.
 */

#ifndef CONTEST__HASHING_H_
#define CONTEST__HASHING_H_

#include <bits/stdc++.h>

static const long long M = INT_MAX;
static long long C; // initialized below, avoid hack

struct HashInterval {
  std::vector<long long> ha, pw;
  HashInterval(std::string &str) : ha(str.size() + 1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.size(); ++i)
      ha[i + 1] = (ha[i] * C % M + str[i]) % M,
          pw[i + 1] = pw[i] * C % M;
  }
  long long hashInterval(int a, int b) { // hash [a, b)
    return (ha[b] - ha[a] * pw[b - a] % M + M) % M;
  }
};

std::vector<long long> getHashes(std::string &str, int length) {
  if (str.size() < length) return {};
  long long h = 0, pw = 1;
  for (int i = 0; i < length; ++i)h = (h * C % M + str[i]) % M, pw = pw * C % M;
  std::vector<long long> ret = {h};
  ret.reserve(str.size() - length + 1);
  for (int i = length; i < str.size(); ++i) {
    ret.push_back((h * C % M + str[i] - pw * str[i - length] % M + M) % M);
    h = ret.back();
  }
  return ret;
}

long long hashString(std::string &s) {
  long long h = 0;
  for (auto c : s)h = (h * C % M + c) % M;
  return h;
}

#include <sys/time.h>
int main() {
  timeval tp;
  gettimeofday(&tp, 0);
  C = tp.tv_usec;
  // ...
}

#endif //CONTEST__HASHING_H_
