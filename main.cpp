//created by su

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace {

#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); \
show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout);

//the ith pos of value to 0
inline void RemoveBitValue(int &value, int index) {
  value &= (~(1 << index));
}

template<class T>
inline std::array<T, 2> sorted(T v1, T v2) {
  if (v1 < v2) { return {v1, v2}; } else { return {v2, v1}; }
}

template<class T>
inline std::array<T, 3> sorted(T v1, T v2, T v3) {
  if (v1 > v3) std::swap(v1, v3);
  if (v1 > v2) std::swap(v1, v2);
  if (v2 > v3) std::swap(v2, v3);
  return std::array<T, 3>{v1, v2, v3};
}

template<class T>
inline T min_value(T v1, T v2, T v3) {
  return std::min(v1, std::min(v2, v3));
}

template<class T>
inline T min_value(T v1, T v2, T v3, T v4) {
  return std::min(std::min(v1, v2), std::min(v3, v4));
}

template<class T>
inline T max_value(T v1, T v2, T v3) {
  return std::max(v1, std::max(v2, v3));
}

template<class T>
inline T max_value(T v1, T v2, T v3, T v4) {
  return std::max(std::max(v1, v2), std::max(v3, v4));
}

template<class T>
void sort_unique(std::vector<T> &vec) {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

template<class T>
void append(std::vector<T> &v1, const std::vector<T> &v2) {
  v1.insert(v1.end(), v2.begin(), v2.end());
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &val) {
  return os << "(" << val.first << "," << val.second << ")";
}

template<class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &values) {
  os << "(";
  for (size_t i = 0; i < values.size(); ++i) {
    os << values[i];
    if (i != values.size() - 1) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values) {
  os << "[";
  for (size_t i = 0; i < values.size(); ++i) {
    const T &x = values[i];
    os << x;
    if (i != values.size() - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os,
                         const std::unordered_set<T> &values) {
  os << "{";
  for (const T &v : values) {
    os << v << ", ";
  }
  os << "}";
  return os;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<T1, T2> &values) {
  os << "{";
  for (const auto &kv : values) {
    os << kv.first << ": " << kv.second << ", ";
  }
  os << "}";
  return os;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &val) {
  os << "[";
  for (auto v = val.begin(); v != val.end(); ++v) {
    if (v != val.begin()) {
      os << ", ";
    }
    os << "(" << v->first << "," << v->second << ")";
  }
  os << "]";
  return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &val) {
  os << "[";
  for (auto v = val.begin(); v != val.end(); ++v) {
    if (v != val.begin()) {
      os << ", ";
    }
    os << (*v);
  }
  os << "]";
  return os;
}

template<typename H1>
std::ostream &show(std::ostream &out, const char *label, H1 &&value) {
  return out << label << "=" << std::forward<H1>(value) << '\n';
}

template<typename H1, typename ...T>
std::ostream &show(std::ostream &out, const char *label,
                   H1 &&value, T &&... rest) {
  const char *p_comma = strchr(label, ',');
  return show(out.write(label, p_comma - label) << "="
                                                << std::forward<H1>(value)
                                                << ',',
              p_comma + 1,
              std::forward<T>(rest)...);
}

//split string with c
std::vector<std::string> SplitStringWith(const std::string &s, char c) {
  std::regex re("\\" + std::string(1, c));
  std::vector<std::string>
      a(std::sregex_token_iterator(s.begin(), s.end(), re, -1),
        std::sregex_token_iterator());
  return a;
}

}

#ifdef LOCAL
//data structure in leetcode

//Definition for singly-linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif

//int g[10000];
//bool vis[260000];

const int mod = 1e9 + 7;
//int dir[4] = { -1,-1,1,1 };
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//int dir[9] = { -1,0,1, -1,0, 1,-1,0,1 };

struct HashInterval {
  std::vector<long long> ha, pw;
  long long c_ = INT_MAX, mod_ = INT_MAX;
 public:
  explicit HashInterval(std::string &str) : ha(str.size() + 1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.size(); ++i)
      ha[i + 1] = (ha[i] * c_ + str[i]) % mod_,
          pw[i + 1] = pw[i] * c_ % mod_;
  }
  long long hashInterval(int a, int b) { // hash [a, b)
    return (ha[b] - ha[a] * pw[b - a] % mod_ + mod_) % mod_;
  }
};


class Solution {
 public:
  vector<int> sumPrefixScores(vector<string> &words) {
    vector<unordered_map<long long,int>>hs(1000);
    vector<HashInterval>his;
    for (int i = 0; i < words.size(); ++i) {
      HashInterval t(words[i]);
      for(int j=0;j<words[i].size();++j){
        hs[j][t.hashInterval(0,j+1)]++;
      }
      his.push_back(t);
    }
    vector<int> ret(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
      for(int j=0;j<words[i].size();++j){
        ret[i]+=hs[j][his[i].hashInterval(0,j+1)];
      }
    }
    return ret;
  }
};

#ifdef LOCAL

int main() {

  return 0;
}

#endif





