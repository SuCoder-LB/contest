//
// Created by su on 2022/3/12.
//

#ifndef CONTEST__LONGEST_COMMON_SUBSEQUENCE_H_
#define CONTEST__LONGEST_COMMON_SUBSEQUENCE_H_

#include <bits/stdc++.h>

template<class T>
T LongestCommonSubsequence(const T &X, const T &Y) {
  int a = X.size(), b = Y.size();
  std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1));
  for (int i = 1; i < a + 1; ++i)
    for (int j = 1; j < b + 1; ++j)
      dp[i][j] = X[i - 1] == Y[j - 1] ?
                 dp[i - 1][j - 1] + 1 : std::max(dp[i][j - 1], dp[i - 1][j]);
  int len = dp[a][b];
  T ans(len, 0);
  while (a && b)
    if (X[a - 1] == Y[b - 1]) ans[--len] = X[--a], --b;
    else if (dp[a][b - 1] > dp[a - 1][b]) --b;
    else --a;
  return ans;
}

template<class T>
T ShortestCommonSuperSequence(const T &X, const T &Y) {
  int a = X.size(), b = Y.size();
  std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1));
  for (int i = 1; i < a + 1; ++i)
    for (int j = 1; j < b + 1; ++j)
      dp[i][j] = X[i - 1] == Y[j - 1] ?
                 dp[i - 1][j - 1] + 1 : std::max(dp[i][j - 1], dp[i - 1][j]);
  int len = X.size() + Y.size() - dp[a][b];
  T ans(len, 0);
  while (len) {
    if (!a) {
      ans[--len] = Y[--b];
      continue;
    }
    if (!b) {
      ans[--len] = X[--a];
      continue;
    }
    if (X[a - 1] == Y[b - 1]) ans[--len] = X[--a], --b;
    else if (dp[a][b - 1] > dp[a - 1][b]) ans[--len] = Y[--b];
    else ans[--len] = X[--a];
  }
  return ans;
}

#endif //CONTEST__LONGEST_COMMON_SUBSEQUENCE_H_
