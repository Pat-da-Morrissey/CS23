/*
  Patrick Morrissey morrisseypd369@gmail.com
  Morrissey1.cpp - Program One (Sets)
*/

#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <vector>

std::set<int> set_maker(int &range) { // creates/returns a set with unique numbers from 1 to 10 within a given range
  std::set<int> temp = {1,2,3,4,5,6,7,8,9,10};

  for(int i = 0; i < 10-range; ++i) {
    auto it = temp.begin();
    do {
      int delete_value = rand() % 10 + 1;
      it = temp.find(delete_value);
    } while (it == temp.end());
    temp.erase(it);
  }
  return temp;
}

std::set<int> compliment(std::set<int> &L, std::set<int> &R) { // creates/returns a complimented set from L = left & R = Rightsets
  std::set<int> comp;
  for(auto left_it = L.begin(); left_it != L.end();) {
    int left_value = *left_it;
    auto right_it = R.find(left_value);
    if(right_it == R.end()) {
      comp.insert(left_value);
    }
    ++left_it;
  }
  return comp;
}

// for the power function I got the main algorithm of this from Geekforgeeks and Chatgpt(it explains how it works). Here is the link to Geekforgeeks
// https://www.geeksforgeeks.org/dsa/power-set/
std::set<std::string> power(std::set<int> &x) { // creates/returns a power set from inputted set
  std::set<std::string> powr = {"{}"};
  std::vector<int> map(x.begin(), x.end());
  int set_size = map.size();
  int range = (1 << set_size);

  for(int i = 0; i < range; ++i) {
    std::string subset = "{ ";
    for(int scanner = 0; scanner < set_size; ++scanner) {
      if(i & (1 << scanner)) {
        subset += std::to_string(map[scanner]) + ", ";
      }
    }
    subset = subset.substr(0, subset.size()-2);
    subset += " }";
    if(subset != " }") { // gets rid of the empty first element
      powr.insert(subset);
    }
  }

  return powr;
}

template <typename T>

void printer(const std::set<T> &x, const std::string &set_name) { // prints out each element in the set, formatted, and compatible for any set type
  std::cout << set_name << " = {";
  for(auto it = x.begin(); it !=  x.end();) {
    std::cout << " " << *it;
    if(++it != x.end()) {
      std::cout << ",";
    }
  }
  std::cout << " }" << std::endl;
}

int main() {
  std::srand(std::time({}));

  int range = (rand() % 3) + 3;  // create a number between 3 and 5
  std::set<int> A = set_maker(range); // creates a random set with that size

  range = (rand() % 3) + 1; // generates a number between 1 and 3
  std::set<int> B = set_maker(range); // create a random set with that size

  printer(A, "A");
  printer(B, "B");

  std::set<int> AcompB = compliment(A, B);
  printer(AcompB, "A - B");
  
  std::set<int> BcompA = compliment(B, A);
  printer(BcompA, "B - A");

  if(AcompB.empty()) {
    std::cout << "A is a subset of B" << std::endl;
  } else {
    std::cout << "A is not a subset of B" << std::endl;
  }

  if(BcompA.empty()) {
    std::cout << "B is a subset of A" << std::endl;
  } else {
    std::cout << "B is not a subset of A" << std::endl;
  }

  std::set<std::string> powA = power(A);
  printer(powA, "P(A)");

  std::set<std::string> powB = power(B);
  printer(powB, "P(B)");

  return 0;
}
