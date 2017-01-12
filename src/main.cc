#include "project_euler_utilities.h"

#include <iostream>
#include <string>
//#include <vector>

int main() {
  std::vector<std::vector<int>> v;
  std::string path = "/Users/home/project-euler-utilities/test/p081_matrix.txt";

  load_csv_to_matrix(path, v);

  for (int i=0; i<v[0].size(); i++) {
    std::cout << v[0][i] << ',';
  }
  std::cout << "\n";
  return 0;
}
