//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_STRINGS_EXTENDED_KMP_H_
#define CONTEST_STRINGS_EXTENDED_KMP_H_
#include "bits/stdc++.h"
const int N = 100002;
int S[N], T[N];
void extKMP(const std::string &s, const std::string &t) {
  int m = t.size(), maT = 0;
  T[0] = 0;
  for (int i = 1; i < m; i++) {
    if (maT + T[maT] >= i) {
      T[i] = std::min(T[i - maT], maT + T[maT] - i);
    } else {
      T[i] = 0;
    }
    while (T[i] + i < m && t[T[i]] == t[T[i] + i])T[i]++;
    if (i + T[i] > maT + T[maT])maT = i;
  }
  int maS = 0, n = s.size();
  for (int i = 0; i < n; i++) {
    if (maS + S[maS] >= i) {
      S[i] = std::min(T[i - maS], maS + S[maS] - i);
    } else {
      S[i] = 0;
    }
    while (S[i] < m && i + S[i] < n && t[S[i]] == s[S[i] + i])S[i]++;
    if (i + S[i] > maS + S[maS])maS = i;
  }
}

#endif //CONTEST_STRINGS_EXTENDED_KMP_H_
