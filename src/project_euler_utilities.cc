
#include "project_euler_utilities.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

void load_csv_to_matrix(const std::string path, std::vector<std::vector<std::string>> &v) {
  std::string line;
  std::ifstream my_file (path);

  if (my_file.is_open()) {
    while (std::getline(my_file, line)) {
      std::vector<std::string> row;
      split(line, ',', row);
      v.push_back(row);
    }
    my_file.close();
  }
  else {
    std::cout << "cannot open file." << std::endl;
  }
}
