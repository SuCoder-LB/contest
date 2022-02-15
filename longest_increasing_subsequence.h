//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_
#define CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_

#include <bits\stdc++.h>

using namespace std;

vector<int> kIncreasing(vector<int> &arr) {
  int n = static_cast<int>(arr.size());

  vector<int> f;
  int length = 0;
  for (int j = 0; j < n; j++) {
    ++length;
    auto it = upper_bound(f.begin(), f.end(), arr[j]);
    if (it == f.end()) {
      f.push_back(arr[j]);
    } else {
      *it = arr[j];
    }
  }
  return f;
}

vector<int> LongestIncreasingSubsequence(vector<int> S) {
  vector<int> prev(S.size());
  vector<array<int,2>> res;
  for(int i=0;i<S.size();++i){
    array<int,2>el={S[i],i};
    auto it= lower_bound(res.begin(),res.end(),array<int,2>{S[i],0});
    if (it == res.end()) res.push_back(el), it = --res.end();
    *it = el;
    prev[i] = it==res.begin() ?0:(*(it-1))[1];
  }

  int L = res.size(), cur = res.back()[1];
  vector<int> ans(L);
  while (L--) ans[L] = cur, cur = prev[cur];
  return ans;
}

#endif //CONTEST__LONGEST_INCREASING_SUBSEQUENCE_H_
