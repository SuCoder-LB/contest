//
// Created by su on 2022/10/13.
//

#ifndef CONTEST__DEBUG_H_
#define CONTEST__DEBUG_H_

#include "bits/stdc++.h"

#define debug(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); \
show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout);

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


std::vector<std::string> SplitStringWith(const std::string &s, char c) {
  std::regex re("\\" + std::string(1, c));
  std::vector<std::string>
      a(std::sregex_token_iterator(s.begin(), s.end(), re, -1),
        std::sregex_token_iterator());
  return a;
}


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
#endif //CONTEST__DEBUG_H_
