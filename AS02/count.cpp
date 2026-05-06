/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  count.cpp - Assignment 02 (Count)
*/

#include <iostream>
#include "count.h"

Counter::Counter() {}
Counter::~Counter() {}

// I found this short code from stackoverflow here is the link: 
// https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c
long Counter::choose(int x, int y) {
    if (y == 0) return 1;
    return (x * choose(x - 1, y - 1)) / y;
}

long Counter::permute(int x , int y) {
  double a = 1;  // x !
  double c = 1;  // (x - y) !

  for (int i = 1; i <= x; ++i) {
    a *= i;
    if (i <= (x-y)) c *= i;
  }
  return a/c;
}

// I like to reference Alan for this code, he helped me out with it!
unsigned int Counter::rderangement(int x) {
  if(x == 0) return 1;
  if(x == 1) return 0;    
  return (x-1)*(rderangement(x-1)+rderangement(x-2));
}

unsigned int Counter::derangement(int x) {
  if(x >= 0 && x <= 13) {
    return known_derangements[x];
  } else {
    return 0;
  }
}

