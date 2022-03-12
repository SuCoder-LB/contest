//
// Created by su on 2022/3/12.
//

#ifndef CONTEST__HAMILTON_PATH_H_
#define CONTEST__HAMILTON_PATH_H_

#include <bits/stdc++.h>

//input edge pair
std::vector<int> HamiltonPath(std::vector<std::vector<int>> &pairs, int n) {
  std::vector<bool> visit(n, false);

  // graph
  std::unordered_map<int, std::vector<int>> edges;
  // in degree,out degree
  std::unordered_map<int, int> in_deg, out_deg;
  for (const auto &p : pairs) {
    int x = p[0], y = p[1];
    edges[x].push_back(y);
    ++in_deg[y];
    ++out_deg[x];
  }

  // find start
  int start = pairs[0][0];
  for (const auto &x : out_deg) {
    // out degree-in degree==1 as start
    if (x.second == in_deg[x.first] + 1) {
      start = x.first;
      break;
    }
  }

  std::vector<int> ans;


  std::function<void(int)> dfs = [&](int u) {
    visit[u] = true;
    ans.push_back(u);

    while (!edges[u].empty()) {
      int v = edges[u].back();
      edges[u].pop_back();
      if (visit[v])continue;
      dfs(v);
    }
  };

  dfs(start);
  return ans;
}

#endif //CONTEST__HAMILTON_PATH_H_
