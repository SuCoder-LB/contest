//
// Created by su on 2022/2/20.
//

#ifndef CONTEST__SEGMENT_TREE_H_
#define CONTEST__SEGMENT_TREE_H_

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  typedef int T;
  static const T LOW = INT_MIN;
  T f(T a, T b) { return a+b; } // (any associative fn)
  vector<T> s; int n;
  SegmentTree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
  void Update(int pos, T val) {
    for (s[pos += n] = val; pos > 1; pos /= 2)
      s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
  }
  T Query(int b, int e) { // query [b, e)
    T ra = 0, rb = 0;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

#endif //CONTEST__SEGMENT_TREE_H_
