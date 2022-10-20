/**
 * Description: Data structure for computing lowest common
 * ancestors in a tree (with 0 as root). C should be an adjacency list of the tree,
 * either directed or undirected.
 * Can also find the distance between two nodes.
 * Usage:
 *  LCA lca(undirGraph);
 *  lca.query(firstNode, secondNode);
 *  lca.distance(firstNode, secondNode);
 * Time: $O(N \log N + Q)$
 */

#ifndef CONTEST_GRAPH_LCA_H_
#define CONTEST_GRAPH_LCA_H_

#include "bits/stdc++.h"

template<class T>
struct RMQ {
  std::vector<std::vector<T>> jmp;

  RMQ(const std::vector<T> &V) {
    int N = V.size(), on = 1, depth = 1;
    while (on < V.size()) on *= 2, depth++;
    jmp.assign(depth, V);
    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j < N; ++j)
        jmp[i + 1][j] = min(jmp[i][j], jmp[i][std::min(N - 1, j + (1 << i))]);
  }

  T query(int a, int b) {
    assert(a < b); // or return inf if a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

struct LCA {
  std::vector<int> time;
  std::vector<long long> dist;
  RMQ<std::pair<int, int>> rmq;

  LCA(std::vector<std::vector<std::pair<int, int>>> &C) : time(C.size(), -99), dist(C.size()), rmq(dfs(C)) {}

  std::vector<std::pair<int, int>> dfs(std::vector<std::vector<std::pair<int, int>>> &C) {
    std::vector<std::tuple<int, int, int, long long>> q(1);
    std::vector<std::pair<int, int>> ret;
    int T = 0, v, p, d;
    long long di;
    while (!q.empty()) {
      std::tie(v, p, d, di) = q.back();
      q.pop_back(), time[v] = T++, dist[v] = di;
      if (d) ret.emplace_back(d, p);
      for (auto e : C[v])if (e.first != p)q.emplace_back(e.first, v, d + 1, di + e.second);
    }
    return ret;
  }

  int query(int a, int b) {
    if (a == b) return a;
    a = time[a], b = time[b];
    return rmq.query(std::min(a, b), std::max(a, b)).second;
  }
  long long distance(int a, int b) {
    int lca = query(a, b);
    return dist[a] + dist[b] - 2 * dist[lca];
  }
};

#endif //CONTEST_GRAPH_LCA_H_
