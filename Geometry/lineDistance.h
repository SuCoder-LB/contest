//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_GEOMETRY_LINEDISTANCE_H_
#define CONTEST_GEOMETRY_LINEDISTANCE_H_
#include <bits/stdc++.h>

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
  return (double)(b-a).cross(p-a)/(b-a).dist();
}
#endif //CONTEST_GEOMETRY_LINEDISTANCE_H_
