//
// Created by su on 2022/2/16.
//

#ifndef CONTEST__EUCLID_H_
#define CONTEST__EUCLID_H_

#include<bits/stdc++.h>

long long gcd(long long a, long long b) {
  return std::__gcd(a, b);
}

//return ax+by=d=gcd(a,b)
long long euclid(long long a, long long b, long long &x, long long &y) {
  if (b) {
    long long d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
  }
  return x = 1, y = 0, a;
}


#endif //CONTEST__EUCLID_H_
