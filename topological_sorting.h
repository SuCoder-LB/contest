//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__TOPOLOGICAL_SORTING_H_
#define CONTEST__TOPOLOGICAL_SORTING_H_
#include <bits\stdc++.h>

using namespace std;

//有向图的最短路径，edges[i]存放第i个点的指向点，第队列可改为优先队列
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

//无向图的拓扑排序(可用于求最短路径)，edges[i]存放所有与i相关联的边
bool TopologicalSorting(const vector<vector<int>> &edges, vector<int> &idx, int n,int s) {
  idx.clear();idx.resize(n,-1);

  queue<int> q; // use priority queue for smallest ans.
  q.push(-s);
  idx[s]=0;
  int nr=0;
  while (!q.empty()) {
    int i = -q.front(); q.pop();++nr;
    for(auto e:edges[i])if(idx[e]==-1)idx[e]=idx[i]+1,q.push(-e);
  }
  return nr == n;
}



#endif //CONTEST__TOPOLOGICAL_SORTING_H_
