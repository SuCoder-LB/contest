//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__MODULAR_POW_H_
#define CONTEST__MODULAR_POW_H_
#include <bits/stdc++.h>

const long long mod = 1e9+7, LIM = 2e6; // faster if const
long long modpow(long long a, long long e) {
  if (e == 0) return 1;
  long long x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}

long long fac[LIM + 5], invfac[LIM + 5];
long long inv(long long a) { return modpow(a, mod - 2); }

void init(int n = LIM) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  invfac[n] = inv(fac[n]);
  for (int i = n; i >= 1; --i) invfac[i - 1] = 1ll * invfac[i] * i % mod;
}

long long C(long long n, long long m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1ll * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

#endif //CONTEST__MODULAR_POW_H_
