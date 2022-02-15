//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__TOPOLOGICAL_SORTING_H_
#define CONTEST__TOPOLOGICAL_SORTING_H_
#include <bits\stdc++.h>

using namespace std;


bool TopologicalSorting(const vector<vector<int>> &edges, vector<int> &idx, int n) {
  vector<int> in_degree(n);
  for(int i=0;i<n;++i)for(auto e:edges[i])++in_degree[e];

  queue<int> q; // use priority queue for smallest ans.
  for(int i=0;i<n;++i)if(!in_degree[i])q.push(-i);
  int nr = 0;
  while (!q.empty()) {
    int i = -q.front(); // top() for priority queue
    idx[i] = nr++;
    q.pop();
    for(auto e:edges[i])if(!(--in_degree[e]))q.push(-e);
  }
  return nr == n;
}


#endif //CONTEST__TOPOLOGICAL_SORTING_H_
