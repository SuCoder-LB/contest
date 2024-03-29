/**
 * Description: Compute indices for the longest increasing subsequence.
 * Time: $O(N \log N)$
 */
#ifndef CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_
#define CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_

#include <bits/stdc++.h>

std::vector<int> lis(std::vector<int> S) {
  std::vector<int> prev(S.size());
  std::vector<std::array<int, 2>> res;
  for (int i = 0; i < S.size(); ++i) {
    std::array<int, 2> el = {S[i], i};
    auto it = lower_bound(res.begin(),
                          res.end(),
                          std::array<int, 2>{S[i],
                                             0});//0 to I not restrict increase
    if (it == res.end()) res.push_back(el), it = --res.end();
    *it = el;
    prev[i] = it == res.begin() ? 0 : (*(it - 1))[1];
  }
  int L = static_cast<int>(res.size()), cur = res.back()[1];
  std::vector<int> ans(L);
  while (L--) ans[L] = cur, cur = prev[cur];
  return ans;
}

#endif //CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_
