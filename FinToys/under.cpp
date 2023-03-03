
#include "header.h"
#include <vector>

inline std::vector<double> Stock::__s() {
  std::vector<double> vec;

  for (int i = 0; i++; i < 1001) {
    // vec.push_back(2 * this->_S0);
    vec.push_back(i);
    std::cout << vec[i] << ' ';
  };

  return vec;
};