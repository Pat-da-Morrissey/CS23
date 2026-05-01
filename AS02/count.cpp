/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  count.cpp - Assignment 02 (Count)
*/

#include <iostream>
#include "count.h"

Counter::Counter() {}
Counter::~Counter() {}

int Counter::choose(int x, int y) {
    if (y == 0) return 1;
    return (x * choose(x - 1, y - 1)) / y;
}

int Counter::permute(int x , int y) {
  double a = 1;  // x !
  double c = 1;  // (x - y) !

  for (int i = 1; i <= x; ++i) {
    a *= i;
    if (i <= (x-y)) c *= i;
  }
  return a/c;
}

int Counter::rderangement(int x) {
  if(x == 0) return 1;
  if(x == 1) return 0;

    
  return (x-1)*(rderangement(x-1)+rderangement(x-2));
}

int Counter::derangement(int x) {
  if(x == 0) return 1;
  if(x == 1) return 0;

  double n = 1;
  double k = 1;
  bool alternate = true;
  for(int i = 1; i <= x; ++i) {
    n *= i;
    if(alternate) {
      k -= (1/n);
      alternate = false;
    } else {
      k += (1/n);
      alternate = true;
    }
  }

  return n * k;
}
