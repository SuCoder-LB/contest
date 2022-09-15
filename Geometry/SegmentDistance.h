//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_GEOMETRY_SEGMENTDISTANCE_H_
#define CONTEST_GEOMETRY_SEGMENTDISTANCE_H_
#include <bits/stdc++.h>
#include "Point.h"
typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
  if (s==e) return (p-s).dist();
  auto d = (e-s).dist2(), t = std::min(d,std::max(.0,(p-s).dot(e-s)));
  return ((p-s)*d-(e-s)*t).dist()/d;
}
#endif //CONTEST_GEOMETRY_SEGMENTDISTANCE_H_
