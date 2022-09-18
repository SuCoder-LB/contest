//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__TRIES_H_
#define CONTEST__TRIES_H_

#include <bits/stdc++.h>

class Trie {
 public:
  std::vector<std::vector<int>> son;
  std::vector<int> cnt;
  int idx;
  /** Initialize your data structure here. */
  Trie() {
    son.push_back(std::vector<int>(26));
    cnt.push_back(0);
    idx = 0;
  }

  /** Inserts a word into the trie. */
  void insert(const std::string &word) {
    int p = 0;
    int n = static_cast<int>(word.size());
    for (int i = 0; i < n; ++i) {
      int u = word[i] - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      if (idx >= son.size()) {
        son.push_back(std::vector<int>(26));
        cnt.push_back(0);
      }
      p = son[p][u];
    }
    cnt[p]++;  //how many words
  }

  /** Returns if the word is in the trie. */
  bool search(const std::string &word) {
    int p = 0;
    int n = static_cast<int>(word.size());
    for (int i = 0; i < n; ++i) {
      int u = word[i] - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }
    if (cnt[p] > 0) return true;
    else return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(const std::string &prefix) {
    int p = 0;
    int n = static_cast<int>(prefix.size());
    for (int i = 0; i < n; ++i) {
      int u = prefix[i] - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }
    return true;
  }
};

#endif //CONTEST__TRIES_H_
