//
// Created by su on 2022/3/12.
//

#ifndef CONTEST__PREFIX_H_
#define CONTEST__PREFIX_H_

#include <bits/stdc++.h>

//2-dim array sum array
void get2sum(const std::vector<std::vector<int>> &grid,
             std::vector<std::vector<int>> &sum) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  sum.resize(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i + 1][j + 1] =
          sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
    }
  }
}

//query 2-dim
//[l,r],[t,d]
int get2ret(const std::vector<std::vector<int>> &sum,
            int t,
            int d,
            int l,
            int r) {
  return sum[d + 1][r + 1] - sum[d + 1][l] - sum[t][r + 1] + sum[t][l];
}

#endif //CONTEST__PREFIX_H_
