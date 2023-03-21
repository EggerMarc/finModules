#include "header.h"
#include "product.hpp"
#include "under.hpp"

int main() {
  double vol = .5;
  double p = 146.3;
  double rate = .2;
  Stock stock(vol, p, rate);
  std::vector<double> vec = stock.__s();

  for (int i = 0; i < 5; i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
