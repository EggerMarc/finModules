
#include "under.hpp"
#include <vector>

std::vector<double> Stock::__s() {
  std::vector<double> vec;
  int n = 1001 / this->_S0;
  for (int i = 0; i < 1001; i++) {
    vec.push_back(2 * this->_S0);
  };

  return vec;
};