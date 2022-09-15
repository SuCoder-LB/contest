//
// Created by su on 2022/3/12.
//

#ifndef CONTEST__HOPCROFT_KARP_H_
#define CONTEST__HOPCROFT_KARP_H_
#include <bits/stdc++.h>

bool dfs(int a,
         int layer,
         const std::vector<std::vector<int>> &g,
         std::vector<int> &btoa,
         std::vector<int> &A,
         std::vector<int> &B) {
  if (A[a] != layer) return 0;
  A[a] = -1;
  for (auto b : g[a])
    if (B[b] == layer + 1) {
      B[b] = -1;
      if (btoa[b] == -1 || dfs(btoa[b], layer + 2, g, btoa, A, B))return btoa[b] = a, 1;
    }
  return 0;
}

int HopcroftKarp(const std::vector<std::vector<int>> &g,
                 std::vector<int> &btoa) {
  int res = 0;
  std::vector<int> A(g.size()), B(btoa.size()), cur, next;
  for (;;) {
    fill(A.begin(), A.end(), 0);
    fill(B.begin(), B.end(), -1);
    cur.clear();
    for (auto a : btoa) if (a != -1) A[a] = -1;
    for (int a = 0; a < g.size(); ++a) if (A[a] == 0) cur.push_back(a);
    for (int lay = 1;; lay += 2) {
      bool islast = 0;
      next.clear();
      for (auto a : cur)
        for (auto b : g[a]) {
          if (btoa[b] == -1) {
            B[b] = lay;
            islast = 1;
          } else if (btoa[b] != a && B[b] == -1) {
            B[b] = lay;
            next.push_back(btoa[b]);
          }
        }
      if (islast) break;
      if (next.empty()) return res;
      for (auto a : next) A[a] = lay + 1;
      cur.swap(next);
    }
    for (int a = 0; a < g.size(); ++a) {
      if (dfs(a, 0, g, btoa, A, B))++res;
    }
  }
}

#endif //CONTEST__HOPCROFT_KARP_H_
