//
// Created by su on 2022/3/11.
//

#ifndef CONTEST__SUFFIX_TREE_H_
#define CONTEST__SUFFIX_TREE_H_

#include <bits/stdc++.h>

struct SuffixTree {
  enum { N = 30, ALPHA = 26 }; // N ~ 2*max_len+10
  int toi(char c) { return c - 'a'; }
  std::string a_; // v = cur node, q = cur position
  int t_[N][ALPHA],l_[N],r_[N],p_[N],s_[N];
  int v_=0,q_=0,m_=2;

  void ukk_add(int i, int c) {
    state:
    if (r_[v_]<=q_) {
      if (t_[v_][c]==-1) {
        t_[v_][c]=m_;  l_[m_]=i;
        p_[m_++]=v_; v_=s_[v_]; q_=r_[v_];
        goto state;
      }
      v_=t_[v_][c]; q_=l_[v_];
    }
    if (q_==-1 || c==toi(a_[q_])) {
      q_++;
    }
    else {
      l_[m_+1]=i;  p_[m_+1]=m_;  l_[m_]=l_[v_];  r_[m_]=q_;
      p_[m_]=p_[v_];  t_[m_][c]=m_+1;  t_[m_][toi(a_[q_])]=v_;
      l_[v_]=q_;  p_[v_]=m_;  t_[p_[m_]][toi(a_[l_[m_]])]=m_;
      v_=s_[p_[m_]];  q_=l_[m_];
      while (q_<r_[m_]) {
        v_=t_[v_][toi(a_[q_])];
        q_+=r_[v_]-l_[v_];
      }
      if (q_==r_[m_])  s_[m_]=v_;
      else s_[m_]=m_+2;
      q_=r_[v_]-(q_-r_[m_]);  m_+=2;
      goto state;
    }
  }

  SuffixTree(const std::string &a) : a_(a) {
    std::fill(r_,r_+N,a.size());
    memset(s_, 0, sizeof s_);
    memset(t_, -1, sizeof t_);
    std::fill(t_[1],t_[1]+ALPHA,0);

    s_[0] = 1; l_[0] = l_[1] = -1; r_[0] = r_[1] = p_[0] = p_[1] = 0;
    for(int i=0;i<a.size();++i) ukk_add(i, toi(a[i]));
  }

  bool search(const std::string &word) {
    int p = 0;
    int n = static_cast<int>(word.size());
    for (int i = 0; i < n; ++i) {
      int u = word[i] - 'a';
      if (!t_[p][u]) return false;
      p = t_[p][u];
    }

    if (p_[p] > 0) return true;
    else return false;
  }


  // example: find longest common substring (uses ALPHA = 28)
  std::array<int,2> best;
  int lcs(int node, int i1, int i2, int olen) {
    if (l_[node] <= i1 && i1 < r_[node]) return 1;
    if (l_[node] <= i2 && i2 < r_[node]) return 2;
    int mask = 0, len = node ? olen + (r_[node] - l_[node]) : 0;
    for(int c=0;c<ALPHA;++c) if (t_[node][c] != -1)
      mask |= lcs(t_[node][c], i1, i2, len);
    if (mask == 3)
      best = max(best, {len, r_[node] - len});
    return mask;
  }
  static std::array<int,2> LCS(std::string &s, std::string &t) {
    SuffixTree st(s + (char)('z' + 1) + t + (char)('z' + 2));
    st.lcs(0, s.size(), s.size() + 1 + t.size(), 0);
    return st.best;
  }
};



#endif //CONTEST__SUFFIX_TREE_H_
