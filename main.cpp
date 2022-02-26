//created by su

#include<bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using PII = pair<int, int>;
using vec2 = array<double, 2>;
using vec3 = array<double, 3>;
using LL = long long;

using id = int;
using id2 = array<id, 2>;
using id3 = array<id, 3>;

#define F(VAR, STA, NB) \
for(int (VAR) = static_cast<int>(STA); (VAR) < static_cast<int>(NB); ++(VAR))

#define FC(VAR, STA, NB, COND) \
for(int (VAR) = static_cast<int>(STA); (VAR) < static_cast<int>(NB); ++(VAR)) \
if (COND)

#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); \
show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout);

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &val);
template<class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &values);
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values);
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<T1, T2> &val);
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &val);
template<class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &val);
template<class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &val);

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

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<T1, T2> &val) {
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
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &val) {
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

template<class T>
void sort_unique(std::vector<T> &vec) {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

template<class T1, class T2>
inline std::vector<T2> dynamic_cast_vector(const std::vector<T1> &pointers) {
  std::vector<T2> output(pointers.size(), NULL);
  for (size_t i = 0; i < pointers.size(); ++i) {
    output[i] = dynamic_cast<T2>(pointers[i]);
  }
  return output;
}

template<class T>
void append(std::vector<T> &v1, const std::vector<T> &v2) {
  v1.insert(v1.end(), v2.begin(), v2.end());
}

template<typename T>
int findLastOf(const T &value, const std::vector<T> &vec) {
  if (vec.size() == 0) return -1;
  auto it = std::find(vec.rbegin(), vec.rend(), value);
  if (it == vec.rend())return -1;
  return (++it).base() - vec.begin();
}

template<typename T>
int findStartOf(const T &value, const std::vector<T> &vec) {
  if (vec.size() == 0) return -1;
  auto it = std::find(vec.begin(), vec.end(), value);
  if (it == vec.end())return -1;
  return it - vec.begin();
}

//the ith pos of value to 0
void RemoveBitValue(int &value, int index) {
  int bit = 1 << index;
  int nMark = 0;
  nMark = (~nMark) ^ bit;
  value &= nMark;
}

//2-dim array sum array
void get2sum(vector<vector<int>> &grid, vector<vector<int>> &sum) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  sum.resize(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i + 1][j + 1] =
          sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
    }
  }
}

//query 2-dim
//[l,r],[t,d]
int get2ret(vector<vector<int>> &sum, int l, int r, int t, int d) {
  return sum[d + 1][r + 1] - sum[d + 1][l] - sum[t][r + 1] + sum[t][r];
}

//input edge pair
vector<int> HamiltonPath(vector<vector<int>> &pairs, int n) {
  vector<bool> visit(n, false);

  // graph
  unordered_map<int, vector<int>> edges;
  // in degree,out degree
  unordered_map<int, int> in_deg, out_deg;
  for (const auto &p : pairs) {
    int x = p[0], y = p[1];
    edges[x].push_back(y);
    ++in_deg[y];
    ++out_deg[x];
  }

  // find start
  int start = pairs[0][0];
  for (const auto &x : out_deg) {
    // out degree-in degree==1 as start
    if (x.second == in_deg[x.first] + 1) {
      start = x.first;
      break;
    }
  }

  vector<int> ans;

  function<void(int)> dfs = [&](int u) {
    visit[u] = true;
    ans.push_back(u);

    while (!edges[u].empty()) {
      int v = edges[u].back();
      edges[u].pop_back();
      if (visit[v])continue;
      dfs(v);
    }
  };

  dfs(start);
  return ans;
}

//let 2-dim array to 1-dim array,barrier fill the border
void fillArrayWithVector(int *after, const vector<vector<int>> &grid,
                         int barrier = 0) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  int cnt = -1;
  int n2 = n + 2;
  for (int i = 0; i < n2; ++i)after[++cnt] = barrier;
  for (int i = 0; i < m; ++i) {
    after[++cnt] = barrier;
    for (int j = 0; j < n; ++j) after[++cnt] = grid[i][j];
    after[++cnt] = barrier;
  }
  for (int i = 0; i < n2; ++i) after[++cnt] = barrier;
}

//split string with c
std::vector<std::string> SplitStringWith(const std::string &s, char c) {
  vector<string> ans;
  istringstream in(s);
  string token;
  while (getline(in, token, c)) {
    ans.push_back(token);
  }
  return ans;

//  regex re(to_string(c));
//  vector<string> a(sregex_token_iterator(s.begin(), s.end(), re, -1),
//                   std::sregex_token_iterator());
//  return a;
}

double cpt(double cur_m,
           double loss,
           double down_rate,
           double limit,
           double achieve) {
  //solve (nm+x)*(1+limit)=(cur_m+x+loss)*(1+achieve);
  //solve (limit-achieve)*x=(cur_m+loss)*(1+achieve)-nm*(1+limit);
  return
      ((cur_m + loss) * (1 + achieve) - cur_m * (1 - down_rate) * (1 + limit))
          / (limit - achieve);
}


//Definition for singly-linked list
#ifdef LOCAL
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

int g[10000];
//bool vis[260000];

const int mod = 1e9 + 7;
//int dir[4] = { -1,-1,1,1 };
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//int dir[9] = { -1,0,1, -1,0, 1,-1,0,1 };



#ifdef LOCAL
signed main() {

  return 0;
}

#endif





