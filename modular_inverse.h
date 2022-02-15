//
// Created by su on 2022/2/15.
//

#ifndef CONTEST__MODULAR_INVERSE_H_
#define CONTEST__MODULAR_INVERSE_H_
#include <bits\stdc++.h>

using namespace std;


vector<long long> ModularInverse(long long a,long long mod){
  vector<long long>inv(a+1,0);
  inv[1]=1;
  for(int i=2;i<=a;++i){
    inv[i]=mod-(mod/i)*inv[mod%i]%mod;
  }
  return inv;
}

#endif //CONTEST__MODULAR_INVERSE_H_
