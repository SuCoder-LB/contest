//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__HASHING_H_
#define CONTEST__HASHING_H_

#include <bits/stdc++.h>

struct H {
  typedef uint64_t ull;
  ull x;
  H(ull x = 0) : x(x) {}
#define OP(O, A, B) H operator O(H o) { ull r = x; asm \
(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
  OP(+, , "d"(o.x))
  OP(*, "mul %1\n", "r"(o.x) : "rdx")
  H operator-(H o) { return *this + ~o.x; }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (long long) 1e11 + 3; // (order ∼ 3e9; random also ok)
struct HashInterval {
  std::vector<H> ha, pw;
  HashInterval(std::string &str) : ha(str.size() + 1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.size(); ++i)
      ha[i + 1] = ha[i] * C + str[i],
          pw[i + 1] = pw[i] * C;
  }
  H hashInterval(int a, int b) { // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
};
std::vector<H> getHashes(std::string &str, int length) {
  if (str.size() < length) return {};
  H h = 0, pw = 1;
  for (int i = 0; i < length; ++i)
    h = h * C + str[i], pw = pw * C;
  std::vector<H> ret = {h};
  for (int i = length; i < str.size(); ++i) {
    ret.push_back(h = h * C + str[i] - pw * str[i - length]);
  }
  return ret;
}
H hashString(std::string &s) {
  H h{};
  for (auto c : s) h = h * C + c;
  return h;
}

#define PRIME 16777619UL
#define OFFSET_BASIS 2166136261UL

//array hash
struct ArrayHash {
  template<class T>
  size_t operator()(const T &key) const {
    int len = key.size_();
    int s = sizeof(key[0]);
    size_t uc = 0xff;
    size_t hash = OFFSET_BASIS;
    for (int n = 0; n < len; ++n) {
      auto p = static_cast<size_t>(key[n]);
      for (int k = s; k--;) {
        hash = (hash ^ (p & uc)) * PRIME;
        p >>= 8;
      }
    }
    return hash;
  }
};

#endif //CONTEST__HASHING_H_
