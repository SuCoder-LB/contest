//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__UNION_FIND_H_
#define CONTEST__UNION_FIND_H_
#include <bits/stdc++.h>

class UF {
 public:
  std::vector<int> parent_;
 public:
  explicit UF(int n) : parent_(n, -1) {}
  int find(int x) { return parent_[x] < 0 ? x : parent_[x] = find(parent_[x]); }
  int size(int x) { return -parent_[find(x)]; }
  bool same_set(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (parent_[x] > parent_[y]) std::swap(x, y);
    parent_[x] += parent_[y];
    parent_[y] = x;
    return true;
  }
};

#endif //CONTEST__UNION_FIND_H_
