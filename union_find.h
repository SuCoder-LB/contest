//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__UNION_FIND_H_
#define CONTEST__UNION_FIND_H_
#include <bits/stdc++.h>

class UnionFind {
 public:
  std::vector<int> parent_;
  std::vector<int> size_;
  int n_, set_count_, max_set_;
 public:
  explicit UnionFind(int n)
      : n_(n), set_count_(n_), parent_(n), size_(n, 1), max_set_(1) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int Find(int x) {
    return parent_[x] == x ? x : parent_[x] = Find(parent_[x]);
  }
  int Size(int x) { return size_[Find(x)]; }
  bool Join(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) {
      return false;
    }
    if (size_[x] < size_[y]) {
      std::swap(x, y);
    }
    parent_[y] = x;
    size_[x] += size_[y];
    max_set_ = std::max(max_set_, size_[x]);
    --set_count_;
    return true;
  }

  bool SameSet(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x == y;
  }

  //TODO:: max_set_ could be changed
  void Isolate(int x) {
    if (x != parent_[x]) {
      parent_[x] = x;
      size_[x] = 1;
      ++set_count_;
    }
  }
};

#endif //CONTEST__UNION_FIND_H_
