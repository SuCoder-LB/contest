/**
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 */

#ifndef CONTEST_DATASTRUCTURES_LAZYSEGMENTTREE_H_
#define CONTEST_DATASTRUCTURES_LAZYSEGMENTTREE_H_
#include "bits/stdc++.h"

struct Node {
  const int inf = 1e9;
  Node *l = 0, *r = 0;
  int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
  Node(std::vector<int> &v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = std::max(l->val, r->val);
    } else val = v[lo];
  }
  //[1..n],,2n,[1..n],[1,2],[3,4],....,[1,4],,
  int query(int L, int R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return std::max(l->query(L, R), r->query(L, R));
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = std::max(l->val, r->val);
    }
  }
  void add(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf) mset += x;
      else madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = std::max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }

  void debug() {
    for (int i = lo; i < hi; ++i) {
      std::cout << query(i, i + 1) << " ";
    }
    std::cout << "\n";
  }

};

struct NodeSum {
  const int inf = 1e9;
  NodeSum *l = 0, *r = 0;
  int lo, hi, mset = 0, madd = 0;
  long long val = 0;
  NodeSum(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
  NodeSum(std::vector<int> &v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new NodeSum(v, lo, mid);
      r = new NodeSum(v, mid, hi);
      val = l->val + r->val;
    } else val = v[lo];
  }
  long long query(int L, int R) {
    if (R <= lo || hi <= L) return 0;
    if (L <= lo && hi <= R) return val;
    push();
    return l->query(L, R) + r->query(L, R);
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) mset = x, val = x * (hi - lo), madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = l->val + r->val;
    }
  }
  void add(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != 0) mset += x;
      else madd += x;
      val += x * (hi - lo);
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = l->val + r->val;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new NodeSum(lo, mid);
      r = new NodeSum(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }

  void debug() {
    for (int i = lo; i < hi; ++i) {
      std::cout << query(i, i + 1) << " ";
    }
    std::cout << "\n";
  }
};
#endif //CONTEST_DATASTRUCTURES_LAZYSEGMENTTREE_H_
