//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__MODULAR_POW_H_
#define CONTEST__MODULAR_POW_H_
#include <bits/stdc++.h>

const long long mod = 1000000007; // faster if const
long long modpow(long long a, long long e) {
  if (e == 0) return 1;
  long long x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}

#endif //CONTEST__MODULAR_POW_H_
