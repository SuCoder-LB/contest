//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__TRIES_H_
#define CONTEST__TRIES_H_

#include <bits\stdc++.h>

using namespace std;

//字典树
const int TrieN = 100010;
class Trie {
 public:
  int son[TrieN][26];
  int cnt[TrieN];
  int idx;
  /** Initialize your data structure here. */
  Trie() {
    memset(son, 0, sizeof(son));
    memset(cnt, 0, sizeof(cnt));
    idx = 0;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    int p = 0;
    int n=static_cast<int>(word.size());
    for (int i = 0; i < n; ++i) {
      int u = word[i] - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
    }
    cnt[p]++;  //以某个字母结尾的单词有多少个
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    int p = 0;
    int n=static_cast<int>(word.size());
    for (int i = 0; i < n; ++i) {
      int u = word[i] - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }

    if (cnt[p] > 0) return true;
    else return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    int p = 0;
    int n=static_cast<int>(prefix.size());
    for (int i = 0; i < n; ++i) {
      int u = prefix[i] - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }
    return true;
  }
};


#endif //CONTEST__TRIES_H_
