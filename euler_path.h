//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__EULER_PATH_H_
#define CONTEST__EULER_PATH_H_

#include <bits\stdc++.h>

using namespace std;

//nodes_out,第一维，点，第二维边，其array[0]为指向点，array[1]为边的id
//共有nedges条边，src为源点，如不确定是环，最好提前判断出点度数-入点度数=1的点作为源点
vector<int> EulerPath(vector<vector<array<int, 2>>>& nodes_out, const vector<int>&nodes_n_ins, int n_edges, int src= 0) {
  int c = 0;
  for(int i=0;i<nodes_out.size();++i)c+=abs(nodes_n_ins[i]-(int)nodes_out[i].size());
  if (c > 2) return {};
  vector<vector<array<int,2>>::iterator> its;
  its.reserve(nodes_out.size());
  for(auto n:nodes_out)its.push_back(n.begin());
  vector<bool> eu(n_edges);
  vector<int> ret, s = {src};
  while(!s.empty()) {
    int x = s.back();
    auto& it = its[x], end = nodes_out[x].end();
    while(it != end && eu[(*it)[1]]) ++it;
    if(it == end) { ret.push_back(x); s.pop_back(); }
    else { s.push_back((*it)[0]); eu[(*it)[1]] = true; }
  }
  if(ret.size()!= n_edges+1)
    ret.clear(); // No Euler cycles/paths.
  // else, non-cycle if ret.front() != ret.back()
  reverse(ret.begin(),ret.end());
  return ret;
}

#endif //CONTEST__EULER_PATH_H_
