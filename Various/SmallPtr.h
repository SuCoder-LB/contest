//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_VARIOUS_SMALLPTR_H_
#define CONTEST_VARIOUS_SMALLPTR_H_
#include <bits/stdc++.h>
#include "BumpAllocator.h"
template<class T> struct ptr {
  unsigned ind;
  ptr(T* p = 0) : ind(p ? unsigned((char*)p - buf) : 0) {
    assert(ind < sizeof buf);
  }
  T& operator*() const { return *(T*)(buf + ind); }
  T* operator->() const { return &**this; }
  T& operator[](int a) const { return (&**this)[a]; }
  explicit operator bool() const { return ind; }
};
#endif //CONTEST_VARIOUS_SMALLPTR_H_
