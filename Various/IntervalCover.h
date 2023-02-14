/**
 * Description: Compute indices of smallest set of intervals covering another interval.
 * Intervals should be [inclusive, exclusive). To support [inclusive, inclusive],
 * change (A) to add \texttt{|| R.empty()}. Returns empty set on failure (or if G is empty).
 * Time: O(N \log N)
 */

#ifndef CONTEST_VARIOUS_INTERVALCOVER_H_
#define CONTEST_VARIOUS_INTERVALCOVER_H_

#include "bits/stdc++.h"

template<class T>
std::vector<int> cover(std::pair<T, T> G, std::vector<std::pair<T, T>> I) {
  std::vector<int> S(I.size()), R;
  iota(S.begin(),S.end(), 0);
  sort(S.begin(),S.end(), [&](int a, int b) { return I[a] < I[b]; });
  T cur = G.first;
  int at = 0;
  while (cur < G.second) { // (A)
    std::pair<T, int> mx = make_pair(cur, -1);
    while (at < I.size() && I[S[at]].first <= cur) {
      mx = max(mx, make_pair(I[S[at]].second, S[at]));
      at++;
    }
    if (mx.second == -1) return {};
    cur = mx.first;
    R.push_back(mx.second);
  }
  return R;
}

#endif //CONTEST_VARIOUS_INTERVALCOVER_H_
