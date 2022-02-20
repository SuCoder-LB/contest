//
// Created by su on 2022/2/20.
//

#ifndef CONTEST__BINARY_INDEXED_TREE_H_
#define CONTEST__BINARY_INDEXED_TREE_H_

#include <bits/stdc++.h>

using namespace std;


struct BinaryIndexedTree {
  vector<long long> s;
  BinaryIndexedTree(int n) : s(n) {}
  void Update(int pos, long long dif) { // a[pos] += dif
    for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
  }
  long long Query(int pos) { // sum of values in [0, pos)
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int LowerBound(long long sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= s.size() && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
};

#endif //CONTEST__BINARY_INDEXED_TREE_H_
