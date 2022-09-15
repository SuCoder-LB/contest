//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_NUMBER_THEORY_MODULARARITHMETIC_H_
#define CONTEST_NUMBER_THEORY_MODULARARITHMETIC_H_

#include "bits/stdc++.h"
#include "euclid.h"

const long long mod = 17; // change to something else
struct Mod {
  long long x;
  Mod(long long xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod);}
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
  Mod operator/(Mod b) { return *this * invert(b); }
  Mod invert(Mod a) {
    long long x, y, g = euclid(a.x, mod, x, y);
    assert(g == 1); return Mod((x + mod) % mod);
  }
  Mod operator^(long long e) {
    if (!e) return Mod(1);
    Mod r = *this ^ (e / 2); r = r * r;
    return e&1 ? *this * r : r;
  }
};
#endif //CONTEST_NUMBER_THEORY_MODULARARITHMETIC_H_
