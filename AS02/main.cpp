#include <iostream>
#include <string>
#include <vector>
#include <sstream>



int main(int argc, char *argv[]) {

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


    std::stringstream ss(commands[0]);
    int num;
    char dump;

    bool isNum = (ss >> num) && !(ss >> dump);

    if(isNum) {
      std::cout << "found num" << commands[0] << std::endl;
    } else {
      std::stringstream ss2(commands[1]);
      isNum = (ss2 >> num) && !(ss2 >> dump);

      if(commands[0] == "rderangement") { // rderangement
        if(commands.size() == 2 && isNum) {
          std::cout << "refdderefing..." << std::endl;
          //funtionj
        } else {
          std::cout << "Error could not process this line!"; 
        }
      } else if(commands[0] == "derangement") { // derangement
        if(commands.size() == 2 && isNum) {
          std::cout << "derefing..." << std::endl;
          //other stff
        } else {
          std::cout << "Error could not process this line!";
        }
      } else {
        std::cout << "Error could not process this line!";
      }
    }

  }




  return 0;
}
