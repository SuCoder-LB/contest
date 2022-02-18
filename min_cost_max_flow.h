//
// Created by su on 2022/2/16.
//

#ifndef CONTEST__MIN_COST_MAX_FLOW_H_
#define CONTEST__MIN_COST_MAX_FLOW_H_

#include <bits/stdc++.h>

using namespace std;

struct MinCostMaxFlow {
  const long long INF = numeric_limits<long long>::max() / 4;

  int n_;
  vector<vector<int>> ed_, red_;
  vector<vector<long long >> cap_, flow_, cost_;
  vector<int> seen_;
  vector<long long > dist_, pi_;
  vector<pair<int,int>> par_;

  explicit MinCostMaxFlow(int N) :
      n_(N), ed_(N), red_(N), cap_(N, vector<long long>(N)), flow_(cap_), cost_(cap_),
      seen_(N), dist_(N), pi_(N), par_(N) {}

  void addEdge(int from, int to, long long cap, long long cost) {
    this->cap_[from][to] = cap;
    this->cost_[from][to] = cost;
    ed_[from].push_back(to);
    red_[to].push_back(from);
  }

  void path(int s) {
    fill(seen_.begin(), seen_.end(), 0);
    fill(dist_.begin(), dist_.end(), INF);
    dist_[s] = 0; long long di;

    priority_queue<pair<long long, int>> q;
    q.push({0, s});

    auto relax = [&](int i, long long cap, long long cost, int dir) {
      long long val = di - pi_[i] + cost;
      if (cap && val < dist_[i]) {
        dist_[i] = val;
        par_[i] = {s, dir};
        q.push({-dist_[i], i});
      }
    };

    while (!q.empty()) {
      s = q.top().second; q.pop();
      seen_[s] = 1; di = dist_[s] + pi_[s];
      for(auto i:ed_[s])if (!seen_[i])
          relax(i, cap_[s][i] - flow_[s][i], cost_[s][i], 1);
      for(auto i:red_[s])if (!seen_[i])
          relax(i, flow_[i][s], -cost_[i][s], 0);
    }
    for(int i=0; i<n_; ++i) pi_[i] = min(pi_[i] + dist_[i], INF);
  }

  array<long long,2> maxflow(int s, int t) {
    long long totflow = 0, totcost = 0;
    while (path(s), seen_[t]) {
      long long fl = INF;
      for (int p,r,x = t; tie(p,r) = par_[x], x != s; x = p)
        fl = min(fl, r ? cap_[p][x] - flow_[p][x] : flow_[x][p]);
      totflow += fl;
      for (int p,r,x = t; tie(p,r) = par_[x], x != s; x = p)
        if (r) flow_[p][x] += fl;
        else flow_[x][p] -= fl;
    }
    for(int i=0; i<n_; ++i)
      for(int j=0; j<n_; ++j)
        totcost += cost_[i][j] * flow_[i][j];
    return {totflow, totcost};
  }

  // If some costs can be negative, call this before maxflow:
  void setpi(int s) { // (otherwise, leave this out)
    fill(pi_.begin(), pi_.end(), INF); pi_[s] = 0;
    int it = n_, ch = 1; long long v;
    while (ch-- && it--)
      for(int i=0; i<n_; ++i) if (pi_[i] != INF)
          for(auto to:ed_[i]) if (cap_[i][to])
              if ((v = pi_[i] + cost_[i][to]) < pi_[to])
                pi_[to] = v, ch = 1;
    assert(it >= 0); // negative cost_ cycle
  }
};

#endif //CONTEST__MIN_COST_MAX_FLOW_H_
