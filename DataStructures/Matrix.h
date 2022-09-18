/**
 * Author: Ulf Lundstrom
 * Date: 2009-08-03
 * License: CC0
 * Source: My head
 * Description: Basic operations on square matrices.
 * Usage: Matrix<int, 3> A;
 *  A.d = {{{{1,2,3}}, {{4,5,6}}, {{7,8,9}}}};
 *  vector<int> vec = {1,2,3};
 *  vec = (A^N) * vec;
 * Status: tested
 */

#ifndef CONTEST_DATASTRUCTURES_MATRIX_H_
#define CONTEST_DATASTRUCTURES_MATRIX_H_
#include <bits/stdc++.h>

template<class T, int N>
struct Matrix {
  typedef Matrix M;
  std::array<std::array<T, N>, N> d{};
  M operator*(const M &m) const {
    M a;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        for (int k = 0; k < N; ++k) a.d[i][j] += d[i][k] * m.d[k][j];
    return a;
  }
  std::vector<T> operator*(const std::vector<T> &vec) const {
    std::vector<T> ret(N);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        ret[i] += d[i][j] * vec[j];
    return ret;
  }
  M operator^(long long p) const {
    assert(p >= 0);
    M a, b(*this);
    for (int i = 0; i < N; ++i)a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};
#endif //CONTEST_DATASTRUCTURES_MATRIX_H_
