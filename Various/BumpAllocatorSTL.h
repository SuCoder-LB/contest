//
// Created by su on 2022/9/15.
//

#ifndef CONTEST_VARIOUS_BUMPALLOCATORSTL_H_
#define CONTEST_VARIOUS_BUMPALLOCATORSTL_H_
#include <bits/stdc++.h>
char buf[450 << 20] ;//alignas(16);
size_t buf_ind = sizeof buf;
template<class T>
struct small {
  typedef T value_type;
  small() {}
  template<class U>
  small(const U &) {}
  T *allocate(size_t n) {
    buf_ind -= n * sizeof(T);
    buf_ind &= 0 - alignof(T);
    return (T *) (buf + buf_ind);
  }
  void deallocate(T *, size_t) {}
};
#endif //CONTEST_VARIOUS_BUMPALLOCATORSTL_H_
