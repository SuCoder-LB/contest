//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__EULER_PATH_H_
#define CONTEST__EULER_PATH_H_

#include <bits/stdc++.h>

using namespace std;

//nodes_out,1-dim，point，2-dim edge，array[0] out point id，array[1] edge id
//nedges the number of edges，src the start of point，if not ensure a circle，better computer the out degree-in degree=1 point as src
vector<int> EulerPath(vector<vector<array<int, 2>>> &nodes_out,
                      const vector<int> &nodes_n_ins,
                      int n_edges,
                      int src = 0) {
  int c = 0;
  for (int i = 0; i < nodes_out.size(); ++i)
    c += abs(nodes_n_ins[i] - (int)nodes_out[i].size());
  if (c > 2) return {};
  vector<vector<array<int, 2>>::iterator> its;
  its.reserve(nodes_out.size());
  for (auto n : nodes_out)its.push_back(n.begin());
  vector<bool> eu(n_edges);
  vector<int> ret, s = {src};
  while (!s.empty()) {
    int x = s.back();
    auto &it = its[x], end = nodes_out[x].end();
    while (it != end && eu[(*it)[1]]) ++it;
    if (it == end) {
      ret.push_back(x);
      s.pop_back();
    } else {
      s.push_back((*it)[0]);
      eu[(*it)[1]] = true;
    }
  }
  if (ret.size() != n_edges + 1)
    ret.clear(); // No Euler cycles/paths.
  // else, non-cycle if ret.front() != ret.back()
  reverse(ret.begin(), ret.end());
  return ret;
}

vector<int> MinPath(const vector<vector<int>> &dis) {
  int n = dis.size();
  vector<vector<int>> dp(1 << n, vector<int>(n, -1)),
      parent(1 << n, vector<int>(n, -1));
  for (int mask = 0; mask < 1 << n; ++mask)
    for (int bit = 0; bit < n; ++bit)
      if ((mask >> bit) & 1) {
        int pmask = mask;
        pmask ^= 1 << bit;
        if (pmask == 0)continue;
        for (int i = 0; i < n; ++i)
          if ((pmask >> i) & 1) {
            int val = dp[pmask][i] + dis[i][bit];
            //DBG(mask,bit,pmask,i,dp[pmask][i],val,dp[mask][bit]);
            if (dp[mask][bit] == -1 || val <= dp[mask][bit]) {
              dp[mask][bit] = val;
              parent[mask][bit] = i;
            }
          }
      }
  //DBG(dp,parent);
  int mask = (1 << n) - 1;
  int p = max_element(dp[mask].begin(), dp[mask].end()) - dp[mask].begin();
  vector<int> ret;
  while (p != -1) {
    ret.push_back(p);
    int pp = parent[mask][p];
    mask ^= 1 << p;
    p = pp;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
#endif //CONTEST__EULER_PATH_H_
