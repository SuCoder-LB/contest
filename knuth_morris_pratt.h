//
// Created by su on 2022/3/1.
//

#ifndef CONTEST__KNUTH_MORRIS_PRATT_H_
#define CONTEST__KNUTH_MORRIS_PRATT_H_

#include <bits/stdc++.h>

using namespace std;

vector<int> pi(const string &s) {
  vector<int> p(s.size());
  for (int i = 1; i < (int)s.size(); ++i) {
    int g = p[i - 1];
    while (g && (s[i] != s[g])) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

vector<int> match(const string &s, const string &pat) {
  vector<int> p = pi(pat + '\0' + s), res;
  for (int i = (int)p.size() - (int)s.size(); i < (int)p.size(); ++i)
    if (p[i] == (int)pat.size()) res.push_back(i - 2 * (int)pat.size());
  return res;
}
#endif //CONTEST__KNUTH_MORRIS_PRATT_H_
