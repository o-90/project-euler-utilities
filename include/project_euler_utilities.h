#ifndef PROJECT_EULER_UTILITIES_H_
#define PROJECT_EULER_UTILITIES_H_

#include <vector>
#include <string>

void split(const std::string &s, char delim, std::vector<int> &elems);
void load_csv_to_matrix(const std::string path, std::vector<std::vector<int>> &v);

#endif  //PROJECT_EULER_UTILITIES_H_
