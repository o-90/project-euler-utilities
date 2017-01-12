#ifndef PROJECT_EULER_UTILITIES_H_
#define PROJECT_EULER_UTILITIES_H_

#include <vector>
#include <string>

void split(const std::string &s, char delim, std::vector<std::string> &elems);
void load_csv_to_matrix(const std::string path, std::vector<std::vector<std::string>> &v);

#endif  //PROJECT_EULER_UTILITIES_H_
