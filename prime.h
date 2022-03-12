//
// Created by su on 2022/3/2.
//

#ifndef CONTEST__PRIME_H_
#define CONTEST__PRIME_H_

#include <bits/stdc++.h>

//all the prime less than lim
const int MAX_PR = 5000000;
std::bitset<MAX_PR> isprime;
std::vector<int> eratosthenes_sieve(int lim) {
  isprime.set(); isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2) isprime[i] = 0;
  for (int i = 3; i*i < lim; i += 2) if (isprime[i])
      for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
  std::vector<int> pr;
  for(int i=2;i<lim;++i) if (isprime[i]) pr.push_back(i);
  return pr;
}

// all the prime factor of lim
std::vector<int>Prime(int lim){
  std::vector<int>primes;
  int x=lim;
  for(int j=2;j*j<=x;++j){
    if(x%j==0){
      while(x%j==0)x/=j;
      primes.push_back(j);
    }
  }
  if(x>1||primes.empty()){
    primes.push_back(x);
  }
  return primes;
}

#endif //CONTEST__PRIME_H_
