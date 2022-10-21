#ifndef CONTEST__MODULAR_POW_H_
#define CONTEST__MODULAR_POW_H_
#include <bits/stdc++.h>

const long long mod = 1000000007, LIM = 5e5; // faster if const
long long modpow(long long a, long long e) {
  if (e == 0) return 1;
  long long x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}

int fac[LIM + 5], invfac[LIM + 5];
long long inv(int a) { return modpow(a, mod - 2); }

void init(int n = LIM) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  invfac[n] = inv(fac[n]);
  for (int i = n; i >= 1; --i) invfac[i - 1] = 1ll * invfac[i] * i % mod;
}

int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1ll * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

//int inv[LIM];
//void invinit() {
//  inv[1] = 1;
//  for (int i = 2; i < LIM; ++i) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
//}

#endif //CONTEST__MODULAR_POW_H_
