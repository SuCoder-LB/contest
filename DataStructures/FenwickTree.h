/**
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 */

#ifndef CONTEST_DATASTRUCTURES_FENWICKTREE_H_
#define CONTEST_DATASTRUCTURES_FENWICKTREE_H_
#include "bits/stdc++.h"
struct FT {
  std::vector<long long> s;
  FT(int n) : s(n) {}
  void update(int pos, long long dif) { // a[pos] += dif
    for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
  }
  long long query(int pos) { // sum of values in [0, pos)
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(long long sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= s.size() && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
};
#endif //CONTEST_DATASTRUCTURES_FENWICKTREE_H_
