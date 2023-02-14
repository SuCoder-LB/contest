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


int length(int l,int r){return r-l;}

std::set<std::pair<int,int>>::iterator addInterval(std::set<std::pair<int,int>>& is, int L, int R,
                                                   std::map<int,std::set<std::pair<int,int>>>&hash) {
  if (L == R) return is.end();
  auto it = is.lower_bound({L, R}), before = it;
  while (it != is.end() && it->first <= R) {
    R = std::max(R, it->second);
    hash[length(it->first,it->second)].erase({it->first,it->second});
    if(hash[length(it->first,it->second)].empty())hash.erase(length(it->first,it->second));
    before = it = is.erase(it);
  }
  if (it != is.begin() && (--it)->second >= L) {
    L = std::min(L, it->first);
    R = std::max(R, it->second);
    hash[length(it->first,it->second)].erase({it->first,it->second});
    if(hash[length(it->first,it->second)].empty())hash.erase(length(it->first,it->second));
    is.erase(it);
  }
  hash[length(L,R)].insert({L,R});
  return is.insert(before, {L,R});
}

void removeInterval(std::set<std::pair<int,int>>& is, int L, int R,
                    std::map<int,std::set<std::pair<int,int>>>&hash) {
  if (L == R) return;
  auto it = addInterval(is, L, R,hash);
  auto r2 = it->second;
  if (it->first == L) {
    hash[length(it->first,it->second)].erase({it->first,it->second});
    if(hash[length(it->first,it->second)].empty())hash.erase(length(it->first,it->second));
    is.erase(it);
  }else{
    hash[length(it->first,it->second)].erase({it->first,it->second});
    if(hash[length(it->first,it->second)].empty())hash.erase(length(it->first,it->second));
    hash[length(it->first,L)].insert({it->first,L});
    (int&)it->second = L;
  }
  if (R != r2) {
    hash[length(R,r2)].insert({R,r2});
    is.emplace(R, r2);
  }
}

#endif //CONTEST_VARIOUS_INTERVALCONTAINER_H_
