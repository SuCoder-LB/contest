//created by su

#include<bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using PII=pair<int,int>;
using vec2 = array<double, 2>;
using vec3 = array<double, 3>;
using LL = long long;

using id = int;
using id2 = array<id, 2>;
using id3 = array<id, 3>;

#define F(VAR,STA, NB) \
for(int (VAR) = static_cast<int>(STA); (VAR) < static_cast<int>(NB); ++(VAR))

#define FC(VAR,STA, NB, COND) \
for(int (VAR) = static_cast<int>(STA); (VAR) < static_cast<int>(NB); ++(VAR)) \
if (COND)

#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); \
show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout);

using std::size_t;

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &val);
template<class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &values);
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &values);
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T1, T2> &val);
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
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T1, T2> &val) {
  os << "[";
  for(auto v=val.begin();v!=val.end();++v){
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
  for(auto v=val.begin();v!=val.end();++v){
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
  for(auto v=val.begin();v!=val.end();++v){
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
  for(auto v=val.begin();v!=val.end();++v){
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
std::ostream& show(std::ostream& out, const char* label,
                   H1&& value, T&&... rest) {
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
      sum[i + 1][j + 1] =
          sum[i + 1][j] + sum[i][j + 1] -sum[i][j] + grid[i][j];
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


//以c划分字符串
std::vector<std::string> SplitStringWith(const std::string &s, char c) {
  vector<string> ans;
  istringstream in(s);
  string token;
  while (getline(in, token, c)) {
    ans.push_back(token);
  }
  //return ans;

  regex re("\\+|i");
  vector<string> a(sregex_token_iterator(s.begin(), s.end(), re, -1), std::sregex_token_iterator());
  return a;
}


double cpt(double curm,double loss,double downrate,double limit,double rechive){
  //solve (nm+x)*(1+limit)=(curm+x+loss)*(1+rechive);
  //solve (limit-rechive)*x=(curm+loss)*(1+rechive)-nm*(1+limit);
  return ((curm+loss)*(1+rechive)-curm*(1-downrate)*(1+limit))/(limit-rechive);
}


//Definition for singly-linked list
#ifdef LOCAL
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

int g[10000];
//bool vis[260000];

const int mod = 1e9 + 7;
//int dir[4] = { -1,-1,1,1 };
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//int dir[9] = { -1,0,1, -1,0, 1,-1,0,1 };


class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(),n=grid[0].size();
    //第一维为拿到钥匙的状态，
    vector<vector<vector<int>>>dp;
    queue<vector<int>>q;
    int cnt=0;//钥匙个数
    int sx,sy;
    for(int i=0;i<m;++i){
      for(int j=0;j<n;++j){
        if(grid[i][j]=='.'||grid[i][j]=='#')continue;
        if(grid[i][j]=='@'){sx=i;sy=j;continue;}
        cnt=max(cnt,grid[i][j]-'a'+1);
      }
    }
    if(cnt==0)return 0;
    int mask=(1<<(cnt+1))-1;
    dp.resize(mask,vector<vector<int>>(m,vector<int>(n,-1)));
    q.push({0,sx,sy,0});//state，x，y，step
    dp[0][sx][sy]=0;

    while(!q.empty()){
      auto poll=q.front();
      int state=poll[0],curx=poll[1],cury=poll[2],step=poll[3];
      for(int d=0;d<4;++d){
        int nextx=curx+dir[d][0],nexty=cury+dir[d][1],nextstate=state,nextstep=step+1;
        if(nextx<0||nextx>=m||nexty<0||nexty>=n||grid[nextx][nexty]=='#')continue;
        if(islower(grid[nextx][nexty])){
          int key=grid[nextx][nexty]-'a';
          nextstate|=(1<<key);
        }
        if(isupper(grid[nextx][nexty])){
          int lock=grid[nextx][nexty]-'A';
          if(!((nextstate>>lock)&1))continue;
        }
        if(nextstate==mask)return nextstep;
        if(dp[nextstate][nextx][nexty]!=-1)continue;
        dp[nextstate][nextx][nexty]=nextstep;
        q.push({nextstate,nextx,nexty,nextstep});
      }
    }
    return -1;
  }
};

#include "longest_increasing_subsequence.h"

#ifdef LOCAL
signed main() {
//  vector<VI>lamps = { {2,0},{1,2} };
//  vector<VI>queries = { {2,3},{0,3} };
//  vector<VI>grid ={ {0, 1, 0, 0, 0, 0, 0, 1},
//                    {0, 1, 0, 0, 0, 0, 0, 1},
//                    {0, 0, 0, 0, 0, 0, 0, 1},
//                    {0, 0, 0, 0, 0, 0, 0, 0} };
//  vector<VI>grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
//  vector<VI> board = {{1, 2, 3}, {4, 0, 5}};
//  vector<VI>intervals = { {1, 3},{1, 4},{2, 5},{3, 5} };
//  vector<VI>intervals= {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
//  VI a={4,1,6,5};
//  VI a={1,2,3,4,5,6};
//  string expr="(e + 8) * (e - 8)";
//  VI q={192,268,359,111,48,322,170,498,51,147,452,153,12,19,437,437,261,484,401,
//        229,277,306,259,135,268,387,174,9,133,20,204,41,322,182,274,302,296,189,
//        93,187,238,234,41,479,203,192,197,135,133,259,428,405,6,329,13,85,57,
//        132,226,345,137,447,352,129,132,478,4,159,112,71,261,39,231,165,427,260,
//        76,145,419,295,340,233,273,491,77,66,401,486,488,447,240,354,205,413,281,
//        196,485,58,200,142,389,133,361,60,484,39,247,268,112,462,207,81,466,433,
//        106,40,430,82,269,222,457,381,213,3,195,87,218,458,462,256,112,158,81,
//        172,399,367,217,388,352,322,142,39,99,464,240,475,382,453,490,38,246,
//        316,237,13,147,398,256,192,134,88,11,281,229,41,392,487,252,146,294,281,
//        63,168,312,388,203,340,334,134,364,279,450,301,364,252,241,491,216,151,
//        301,343,362,226,325,395,339,260,320,32,137,352,188,328,453,492,19,414,5,
//        250,101,375,301,423,270,60,11,372,18,298,217,203,78,427,57,272,389,494,
//        33,436,217,115,366,498,398,409,210,302,11,28,98,312,470,375,52,304,273,
//        240,218,441,188,101,354,98,298,261,217,125,406,355,317,76,484,292,401,
//        89,234,373,50,227,452,23,445,437,366,477,304,98,447,94,408,451,432,247,
//        204,279,319,138,459,420,337,285,409,217,242,242,413,359,100,58,465,476,
//        80,421,409,40,233,87,90,212,297,169,181,367,348,88,9,144,405,232,292,
//        336,418,83,115,196,135,269,182,120,77,418,107,469,123,266,219,51,208,
//        480,164,177,392,328,419,283,464,257,80,167,418,314,215,192,180,257,321,
//        46,460,87,9,60,257,431,494,344,222,144,265,388,260,434,56,323,184,445,
//        228,326,219,40,2,84,143,489,471,280,33,32,278,25,431,314,480,241,223,
//        286,334,76,271,205,461,202,15,248,462,232,4,237,272,100,93,98,346,233,
//        102,475,51,453,158,99,484,350,174,218,216,110,278,79,24,127,26,350,329,
//        125,386,229,355,257,8,382,251,291,400,400,437,171,478,21,3,303,419,99,5,
//        189,71,247,274,497,163,109,160,117,28,408,84,381,300,81,360,218,145,253,
//        119,75,254,498,139,171,167,415,242,39,222,406,355,97,93,376,61,355,10,
//        499,295,303,90,73,453,114,392,238,43,115};
//  VI s={360,268,132,295,144,189,478,104,143,135,427,193,324,11,498,236,227,93,
//        308,295,350,114,288,279,264,48,92,60,81,106,167,98,134,349,366,196,471,
//        449,116,51,395,4,190,109,15,358,347,322,192,98,434,2,334,407,176,42,187,
//        87,67,326,378,288,488,46,369,55,64,203,265,422,246,428,391,415,351,333,
//        426,257,33,35,9,275,334,230,70,412,77,200,388,192,35,269,483,474,456,42,
//        361,402,485,382,500,463,498,184,372,414,204,344,282,342,262,482,479,267,
//        78,68,150,275,158,404,259,195,296,286,253,34,109,490,304,291,291,410,
//        146,28,191,480,61,366,452,337,431,137,470,183,160,195,142,416,144,142,
//        173,145,426,61,103,112,232,445,264,55,500,232,467,351,288,80,88,471,391,
//        126,36,159,465,220,349,278,248,279,208,369,209,477,113,131,215,187,40,
//        108,25,207,318,43,304,294,127,278,339,366,254,241,361,472,490,449,459,
//        212,322,203,150,72,74,121,69,152,129,344,387,158,74,465,71,476,42,378,
//        470,282,375,403,43,426,258,336,420,99,488,114,415,428,79,320,93,422,48,
//        281,43,477,313,79,287,212,108,126,206,166,138,349,366,478,42,235,162,
//        288,76,120,161,322,452,305,320,356,498,19,164,378,488,106,495,411,385,3,
//        227,458,115,473,34,460,370,76,321,260,5,242,96,115,390,222,145,358,67,
//        123,405,183,406,282,18,37,66,406,161,117,227,153,136,39,112,386,296,340,
//        429,2,483,96,381,325,165,141,350,10,458,454,64,107,261,358,462,86,209,
//        285,97,320,77,74,59,138,466,206,332,331,196,216,401,45,364,26,430,378,
//        394,280,389,452,269,102,307,224,299,383,294,203,118,265,343,283,265,100,
//        385,120,361,439,417,298,315,125,463,112,326,129,213,463,286,109,405,35,
//        143,423,179,239,319,404,141,194,126,490,470,492,61,435,372,189,266,27,
//        34,33,36,361,42,493,56,359,46,453,9,426,44,485,81,394,250,465,481,346,
//        240,10,342,419,137,63,453,370,35,232,205,51,292,266,229,172,489,322,309,
//        350,307,209,135,264,124,279,328,282,112,49,264,46,200,169,16,105,154,
//        449,140,175,500,479,157,197,272,84,201,260,327,181,412,495,328,465,146,
//        109,188,58,366,444,238,427,282,230,432,278,249,89,80,91};


  VI a={47,72,94,31,93,18,18,36,45,1},b={4,1,0,2,3};

  unordered_map<double,pair<unordered_set<char>,map<array<int,2>,set<vector<long>>>>>hash;
  array<int,2>d={2,1};
  vector<long>c={1,312};
  hash[1.3]={{'a','b'},{{{1,2},{{3,4},{5,6,7}}},{{1,3},{{3,4},{5,6,7}}}}};
  hash[6.3]={{'c','d'},{{{4,6},{{1,3},{9,5,3}}},{{5,2},{{8,7,1},{5,8,7,4}}}}};
  DBG(hash);
  //hash[1.3][{2,1}].insert({{2,312},{'b','c'}});
  //hash[1.3][{2,2}].insert({{2,312},{'b','c'}});
  //hash[1.3][{2,2}].insert({{2,332},{'b','c'}});
  //hash[6.21][{2,2}].insert({{3,789},{'h','c'}});
  //DBG(hash);

  auto it=a.end();
  //(*(--it));
  //a.push_back(3);
  DBG(it==a.end());
  DBG(*(--it));
  //Solution().mincostToHireWorkers2(q,s,25);
//Solution().coutPairs(a,30);
  return 0;
}

#endif





