/**
 * Description: When you need to dynamically allocate many objects and don't care about freeing them.
 * "new X" otherwise has an overhead of something like 0.05us + 16 bytes per allocation.
 * Status: tested
 */

#ifndef CONTEST_VARIOUS_BUMPALLOCATOR_H_
#define CONTEST_VARIOUS_BUMPALLOCATOR_H_
#include <bits/stdc++.h>
static char buf[450 << 20];
void *operator new(size_t s) {
  static size_t i = sizeof buf;
  assert(s < i);
  return (void *) &buf[i -= s];
}
void operator delete(void *) {}

// hash-cpp-all = 745db225903de8f
#endif //CONTEST_VARIOUS_BUMPALLOCATOR_H_
