//created by su

#include<bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using vec2 = array<double, 2>;
using vec3 = array<double, 3>;
using LL = long long;

using id = int;
using id2 = array<id, 2>;
using id3 = array<id, 3>;

#define F(VAR,STA, NB) for(int (VAR) = static_cast<int>(STA); (VAR) < static_cast<int>(NB); ++(VAR))
#define FC(VAR, NB, COND) for(int (VAR) = 0; (VAR) < static_cast<int>(NB); ++(VAR)) if (COND)

#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout);

using std::size_t;
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

template<typename H1>
std::ostream &show(std::ostream &out, const char *label, H1 &&value) {
  return out << label << "=" << std::forward<H1>(value) << '\n';
}

template<typename H1, typename ...T>
std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
  const char* pcomma = strchr(label, ',');
  return show(out.write(label, pcomma - label) << "="
                                               << std::forward<H1>(value)
                                               << ',',
              pcomma + 1,
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

//value第index位置0
void RemoveBitValue(int &value, int index) {
  int bit = 1 << index;
  int nMark = 0;
  nMark = (~nMark) ^ bit;
  value &= nMark;
}


//二维前缀和
void get2sum(vector<vector<int>> &grid, vector<vector<int>> &sum) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  sum.resize(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
    }
  }
}

//二维前缀和查询
//[l,r],[t,d]
int get2ret(vector<vector<int>> &sum, int l, int r, int t, int d) {
  return sum[d + 1][r + 1] - sum[d + 1][l] - sum[t][r + 1] + sum[t][r];
}

//有向图的hamilton路径
//输入为每个有向边
vector<int> HamiltonPath(vector<vector<int>> &pairs, int n) {
  vector<bool> visit(n, false);

  // 存储图
  unordered_map<int, vector<int>> edges;
  // 存储入度和出度
  unordered_map<int, int> in_deg, out_deg;
  for (const auto &p : pairs) {
    int x = p[0], y = p[1];
    edges[x].push_back(y);
    ++in_deg[y];
    ++out_deg[x];
  }

  // 寻找起始节点
  int start = pairs[0][0];
  for (const auto &x : out_deg) {
    // 如果有节点出度比入度恰好多 1，那么只有它才能是起始节点
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

//降维加速，barrier为周围四边的填充
void fillArrayWithVector(int *after, const vector<vector<int>> &grid, int barrier = 0) {
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


//以c划分字符串
std::vector<std::string> SplitStringWith(const std::string &s, char c) {
  vector<string> ans;
  istringstream in(s);
  string token;
  while (getline(in, token, c)) {
    ans.push_back(token);
  }
  return ans;
}


//int g[260000];
//bool vis[260000];

const int mod = 1e9 + 7;
int dir[4] = { -1,-1,1,1 };
//int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//int dir[9][2] = { {-1,-1}, {-1,0},{-1,1}, {0,-1},{0,0}, {0,1},{1,-1},{1,0},{1,1} };
//int dir[9] = { -1,0,1, -1,0, 1,-1,0,1 };


#include "min_cost_max_flow.h"

class Solution {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    int n = nums.size();
    int m = numSlots;
    MinCostMaxFlow mcmf(n + m + 2);
    int s = n + m, t = s + 1;
    //F(i,0,n+m+2)mcmf.setpi(i);
    F(i, 0, n){
      mcmf.addEdge(s, i, 1, 0);
      F(j, 0, m) {
        mcmf.addEdge(i, j + n, 1, -(nums[i] & (j + 1)));
      }
    }
    F(i, 0, m) {
      mcmf.addEdge(i + n, t, 2, 0);
    }
    mcmf.setpi(s);
    return -(mcmf.maxflow(s, t))[1];
  }
};


#ifdef LOCAL
signed main() {
  //vector<VI>lamps = { {2,0},{1,2} };
  //vector<VI>queries = { {2,3},{0,3} };
  //vector<VI>grid ={ {0, 1, 0, 0, 0, 0, 0, 1},{0, 1, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 0} };
  //vector<VI>grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  //vector<VI> board = {{1, 2, 3}, {4, 0, 5}};
  //vector<VI>intervals = { {1, 3},{1, 4},{2, 5},{3, 5} };
  //vector<VI>intervals= {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
  //VI a={4,1,6,5};
  //VI a={1,2,3,4,5,6};
  //string expr="(e + 8) * (e - 8)";

  return 0;
}

#endif





