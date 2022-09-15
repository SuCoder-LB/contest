/**
 * Description: Add and remove intervals from a set of disjoint intervals.
 * Will merge the added interval with any overlapping intervals in the set when adding.
 * Intervals are [inclusive, exclusive).
 * Time: O(\log N)
 */
#ifndef CONTEST_VARIOUS_INTERVALCONTAINER_H_
#define CONTEST_VARIOUS_INTERVALCONTAINER_H_

#include "bits/stdc++.h"

std::set<std::pair<int,int>>::iterator addInterval(std::set<std::pair<int,int>>& is, int L, int R) {
  if (L == R) return is.end();
  auto it = is.lower_bound({L, R}), before = it;
  while (it != is.end() && it->first <= R) {
    R = std::max(R, it->second);
    before = it = is.erase(it);
  }
  if (it != is.begin() && (--it)->second >= L) {
    L = std::min(L, it->first);
    R = std::max(R, it->second);
    is.erase(it);
  }
  return is.insert(before, {L,R});
}

void removeInterval(std::set<std::pair<int,int>>& is, int L, int R) {
  if (L == R) return;
  auto it = addInterval(is, L, R);
  auto r2 = it->second;
  if (it->first == L) is.erase(it);
  else (int&)it->second = L;
  if (R != r2) is.emplace(R, r2);
}
#endif //CONTEST_VARIOUS_INTERVALCONTAINER_H_
