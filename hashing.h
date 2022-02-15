//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__HASHING_H_
#define CONTEST__HASHING_H_

#include <bits\stdc++.h>

using namespace std;

#define PRIME 16777619UL
#define OFFSET_BASIS 2166136261UL

//数组hash
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


struct HashInterval {
  vector<long long> ha, pw;
  long long c_=INT_MAX,mod_=INT_MAX;
 public:
  explicit HashInterval(string& str) : ha(str.size()+1), pw(ha) {
    pw[0] = 1;
    for(int i=0;i<str.size();++i)
      ha[i+1] = (ha[i] * c_ + str[i])%mod_,
      pw[i+1] = pw[i] * c_%mod_;
  }
  long long hashInterval(int a, int b) { // hash [a, b)
    return (ha[b] - ha[a] * pw[b - a]%mod_+mod_)%mod_;
  }
};

vector<long long> GetHashes(string& str, int length,long long c,long long mod) {
  if (str.size() < length) return {};
  long long h = 0, pw = 1;
  for(int i=0;i<length;++i)h = (h * c + str[i])%mod, pw = pw * c%mod;
  vector<long long> ret = {h - 0};
  ret.reserve(str.size() - length + 1);
  for(int i=length;i<str.size();++i){
    ret.push_back((h * c + str[i] - pw * str[i-length]+mod)%mod);
    h = ret.back();
  }
  return ret;
}

long long HashString(string& s,long long c,long long mod) {
  long long h = 0;
  for(auto ch:s)h=(h*c+ch)%mod;
  return h - 0;
}
#endif //CONTEST__HASHING_H_
