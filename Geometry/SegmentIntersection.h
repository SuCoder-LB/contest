//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_GEOMETRY_SEGMENTINTERSECTION_H_
#define CONTEST_GEOMETRY_SEGMENTINTERSECTION_H_
#include <bits/stdc++.h>

template<class P>
int segmentIntersection(const P &s1, const P &e1,
                        const P &s2, const P &e2, P &r1, P &r2) {
  if (e1 == s1) {
    if (e2 == s2) {
      if (e1 == e2) {
        r1 = e1;
        return 1;
      } //all equal
      else return 0; //different point segments
    } else return segmentIntersection(s2, e2, s1, e1, r1, r2);//swap
  }
//segment directions and separation
  P v1 = e1 - s1, v2 = e2 - s2, d = s2 - s1;
  auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
  if (a == 0) { //if parallel
    auto b1 = s1.dot(v1), c1 = e1.dot(v1),
        b2 = s2.dot(v1), c2 = e2.dot(v1);
    if (a1 || a2 || max(b1, min(b2, c2)) > min(c1, max(b2, c2)))
      return 0;
    r1 = min(b2, c2) < b1 ? s1 : (b2 < c2 ? s2 : e2);
    r2 = max(b2, c2) > c1 ? e1 : (b2 > c2 ? s2 : e2);
    return 2 - (r1 == r2);
  }
  if (a < 0) {
    a = -a;
    a1 = -a1;
    a2 = -a2;
  }
  if (0 < a1 || a < -a1 || 0 < a2 || a < -a2)
    return 0;
  r1 = s1 - v1 * a2 / a;
  return 1;
}
#endif //CONTEST_GEOMETRY_SEGMENTINTERSECTION_H_
