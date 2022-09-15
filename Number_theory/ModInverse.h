//
// Created by su on 2022/9/15.
//

#ifndef CONTEST__MODINVERSE_H_
#define CONTEST__MODINVERSE_H_
#include <bits/stdc++.h>

void ModularInverse() {
  const long long mod = 1000000007, LIM = 200000;
  long long *inv = new long long[LIM] - 1;inv[1] = 1;
  for(int i = 2; i<LIM; ++i) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
}

#endif //CONTEST__MODINVERSE_H_
