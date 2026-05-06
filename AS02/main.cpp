/*
  Patrick Morrissey pmorriss morrisseypd369@gmail.com
  main.cpp - Assignment 02 (Count)
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "count.h"


int main(int argc, char *argv[]) {
  Counter Count;
  std::string input;

  while(getline(std::cin, input)){
    std::string param;
    std::vector<std::string> commands;
    for(char i : input) {
      if(i == ' ') {
        commands.push_back(param);
        param = "";
      } else {
        param += i;
      }
    }
    if (!param.empty()) {
      commands.push_back(param);
    }

// The code I got inspiration for the stringstream is from geekforgeeks here is the link:
// https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
    std::stringstream ss0(commands[0]);
    int num;
    char dump;

    bool isNum = (ss0 >> num) && !(ss0 >> dump);

    if(isNum) {
      std::stringstream ss1(commands[2]);
      isNum = (ss1 >> num) && !(ss1 >> dump);

      if(commands[1] == "choose" && isNum) { // choose
        std::cout << Count.choose(std::stoi(commands[0]), std::stoi(commands[2])) << std::endl;
      } else if(commands[1] == "permute" && isNum) { // premute
        std::cout << Count.permute(std::stoi(commands[0]), std::stoi(commands[2])) << std::endl;
      } else { //error
        std::cout << "Error could not process this line!" << std::endl;
      }
    } else {
      std::stringstream ss2(commands[1]);
      isNum = (ss2 >> num) && !(ss2 >> dump);

      if(commands[0] == "rderangement") { // rderangement
        if(commands.size() == 2 && isNum) {
          if(std::stoi(commands[1]) <= 13) {
            std::cout << Count.rderangement(std::stoi(commands[1])) << std::endl;
          }
        }
      } else if(commands[0] == "derangement") { // derangement
        if(commands.size() == 2 && isNum) {
          if(std::stoi(commands[1]) <= 13) {
            std::cout << Count.derangement(std::stoi(commands[1])) << std::endl;
          }
        }
      } else { // error
        std::cout << "Error could not process this line!";
      }
    }

  }

  return 0;
}

