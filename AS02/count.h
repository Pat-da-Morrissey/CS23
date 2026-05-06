/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  count.h - Assignment 03 (Count)
*/

#ifndef COUNT_H
#define COUNT_H

  class Counter{
   public:
    Counter();
    ~Counter();

    long choose(int x, int y);
    long permute(int x, int y);
    unsigned int rderangement(int x);
    unsigned int derangement(int x);
  
   private:
  
    unsigned int known_derangements[14] = {1,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841,2290792932};

  };

#endif

