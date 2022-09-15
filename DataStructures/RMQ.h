/**
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 */

#ifndef CONTEST_DATASTRUCTURES_RMQ_H_
#define CONTEST_DATASTRUCTURES_RMQ_H_
#include "bits/stdc++.h"

template<class T>
struct RMQ {
  std::vector<std::vector<T>> jmp;

  RMQ(const std::vector<T> &V) {
    int N = sz(V), on = 1, depth = 1;
    while (on < sz(V)) on *= 2, depth++;
    jmp.assign(depth, V);
    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j < N; ++j)
        jmp[i + 1][j] = min(jmp[i][j],
                            jmp[i][std::min(N - 1, j + (1 << i))]);
  }

  T query(int a, int b) {
    assert(a < b); // or return inf if a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};
#endif //CONTEST_DATASTRUCTURES_RMQ_H_
