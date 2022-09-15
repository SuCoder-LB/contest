//
// Created by su on 2022/9/15.
//

#ifndef CONTEST__SOLVELINEARBINARY_H_
#define CONTEST__SOLVELINEARBINARY_H_
#include <bits/stdc++.h>

const int N=1000;
int solveLinear(std::vector<std::bitset<N>> &A, std::vector<int> &b, std::bitset<N> &x, int m) {
  int n = A.size(), rank = 0, br;
  assert(m <= x.size());
  std::vector<int> col(m);
  iota(col.begin(), col.end(), 0);
  for (int i = 0; i < n; ++i) {
    for (br = i; br < n; ++br) if (A[br].any()) break;
    if (br == n) {
      for (int j = i; j < n; ++j) if (b[j]) return -1;
      break;
    }
    int bc = (int) A[br]._Find_next(i - 1);
    std::swap(A[i], A[br]);
    std::swap(b[i], b[br]);
    std::swap(col[i], col[bc]);
    for (int j = 0; j < n; ++j)
      if (A[j][i] != A[j][bc]) {
        A[j].flip(i);
        A[j].flip(bc);
      }
    for (int j = i + 1; j < n; ++j)
      if (A[j][i]) {
        b[j] ^= b[i];
        A[j] ^= A[i];
      }
    rank++;
  }
  x = std::bitset<N>();
  for (int i = rank; i--;) {
    if (!b[i]) continue;
    x[col[i]] = 1;
    for (int j = 0; j < i; ++j) b[j] ^= A[j][i];
  }
  return rank; // (multiple solutions if rank < m)
}
#endif //CONTEST__SOLVELINEARBINARY_H_
