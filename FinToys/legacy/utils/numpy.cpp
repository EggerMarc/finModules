#include <iostream>
#include <type_traits>
#include <vector>

template <typename T, typename U> bool type_check(T a, U b) {
  return (typeid(a).name() == typeid(b).name()) ? 1 : 0;
}

template <typename T> void printv(std::vector<T> vec) {
  std::cout << "[";
  for (T i : vec) {

    if (type_check(i, vec)) {
      // printv(i);
      // std::cout << typeid(i).name();
    } else {
      // std::cout << typeid(i).name();
      std::cout << i << ", ";
    }
  }

  std::cout << "\b\b]\n" << std::endl;
}

std::vector<double> linspace(double a, double b, double c) {
  // linspace(0,10,10) = [0,1,2,3,4,5,6,7,8,9,10]
  // linspace(0,1,5) = [0,0.2,0.4,0.6,0.8,1]
  // double ERROR = 1e-1; // I guess for now..

  std::vector<double> vec;
  double frac = b / c - 1;
  for (double i = a; i <= b; i += frac) {
    vec.push_back(i);
  }
  return vec;
}

template <typename T> std::vector<int> shape(std::vector<T> vec) {
  std::vector<int> shape;

  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "\nvec.begin(): " << *vec.begin()
            << "\tvec.end(): " << *vec.end();

  return shape;
}

template <typename T>
std::vector<double> dot(std::vector<T> a, std::vector<T> b) {
  // Check matching shapes
  std::vector<int> shape;
}
