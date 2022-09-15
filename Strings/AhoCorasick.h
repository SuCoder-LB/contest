//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_STRINGS_AHOCORASICK_H_
#define CONTEST_STRINGS_AHOCORASICK_H_

#include "bits/stdc++.h"

struct AhoCorasick {
  enum { alpha = 26, first = 'A' };
  struct Node {
    // (nmatches is optional)
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  std::vector<Node> N;
  std::vector<int> backp;
  void insert(const std::string &s, int j) {
    assert(!s.empty());
    int n = 0;
    for (auto c : s) {
      int &m = N[n].next[c - first];
      if (m == -1) {
        n = m = N.size();
        N.emplace_back(-1);
      }
      else n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(std::vector<std::string> &pat) {
    N.emplace_back(-1);
    for (int i = 0; i < pat.size(); ++i) insert(pat[i], i);
    N[0].back = N.size();
    N.emplace_back(0);
    std::queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1) ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
              = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
  std::vector<int> find(std::string word) {
    int n = 0;
    std::vector<int> res; // ll count = 0;
    for (auto c : word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
// count += N[n].nmatches;
    }
    return res;
  }
  std::vector<std::vector<int>> findAll(std::vector<std::string> &pat, std::string word) {
    std::vector<int> r = find(word);
    std::vector<std::vector<int>> res(word.size());
    for (int i = 0; i < word.size(); ++i) {
      int ind = r[i];
      while (ind != -1) {
        res[i - pat[ind].size() + 1].push_back(ind);
        ind = backp[ind];
      }
    }
    return res;
  }
};
#endif //CONTEST_STRINGS_AHOCORASICK_H_
