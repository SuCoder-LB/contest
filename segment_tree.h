//
// Created by su on 2022/2/20.
//

#ifndef CONTEST__SEGMENT_TREE_H_
#define CONTEST__SEGMENT_TREE_H_

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
  typedef long long T;
  static const T LOW = INT_MIN;
  T f(T a, T b) { return a + b; } // (any associative fn)
  vector<T> s;
  int n;
  SegmentTree(int n = 0, T def = 0) : s(2 * n, def), n(n) {}
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
  int LowerBound(long long sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= s.size() && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};

#endif //CONTEST__SEGMENT_TREE_H_
