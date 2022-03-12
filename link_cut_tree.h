//
// Created by su on 2022/3/9.
//

#ifndef CONTEST__LINK_CUT_TREE_H_
#define CONTEST__LINK_CUT_TREE_H_

#include <bits/stdc++.h>


class LinkCutTree {
 public:
  bool rr;
  LinkCutTree *son[2], *pf, *fa;
 public:
  void DownDate() {
    if (rr) {
      if (son[0])son[0]->rr = !son[0]->rr;
      if (son[1])son[1]->rr = !son[1]->rr;
      std::swap(son[0], son[1]);
      rr = false;
    }
    // add stuff
  }
  void update() {
    // add stuff
  }
  void rotate(bool t) {
    LinkCutTree *y = fa;
    assert(y != nullptr);
    LinkCutTree *z = y->fa;
    if (z != nullptr) z->son[z->son[1] == y] = this;
    fa = z;
    y->son[t] = son[!t];
    if (son[!t])son[!t]->fa = y;
    son[!t] = y;
    y->fa = this;
    y->update();
  }
  void xiao() {
    if (fa != nullptr) fa->xiao(), pf = fa->pf;
    DownDate();
  }
  void splay() {
    xiao();
    LinkCutTree *y, *z;
    while (fa != nullptr) {
      y = fa;
      z = y->fa;
      bool t1 = (y->son[1] == this), t2 = (z == nullptr ? -1 : z->son[1] == y);
      if (z != nullptr) {
        if (t1 == t2) y->rotate(t2), rotate(t1);
        else rotate(t1), rotate(t2);
      } else rotate(t1);
    }
    update();
  }
  void access() {
    splay();
    son[1]->pf = this;
    son[1]->fa = nullptr;
    son[1] = nullptr;
    update();
    while (pf != nullptr) {
      pf->splay();
      pf->son[1]->pf = pf;
      pf->son[1]->fa = nullptr;
      pf->son[1] = this;
      fa = pf;
      splay();
    }
    rr = true;
  }
  bool Cut(LinkCutTree *y) {
    access();
    y->access();
    y->DownDate();
    DownDate();
    if (y->son[1] != this || son[0] != nullptr)
      return false;
    y->son[1] = nullptr;
    fa = pf = nullptr;
    update();
    y->update();
    return true;
  }
  bool Connected(LinkCutTree *y) {
    access();
    y->access();
    return this == y || fa != nullptr;
  }
  bool Link(LinkCutTree *y) {
    if (Connected(y))
      return false;
    access();
    y->access();
    pf = y;
    return true;
  }

};





#endif //CONTEST__LINK_CUT_TREE_H_
