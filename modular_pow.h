//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__MODULAR_POW_H_
#define CONTEST__MODULAR_POW_H_
#include <bits\stdc++.h>

using namespace std;


long long ModularPow(long long a, long long e, const long long mod) {
  if (e == 0) return 1;
  long long x = ModularPow(a * a % mod, e >> 1,mod);
  return e & 1 ? x * a % mod : x;
}

#endif //CONTEST__MODULAR_POW_H_
