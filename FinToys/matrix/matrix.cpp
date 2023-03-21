#include "matrix.hpp"

// Private Getters
template <typename T> int Matrix<T>::get_columns() { return this->rows(); }
template <typename T> int Matrix<T>::get_rows() { return this->columns(); }

//Public Getters and Setters
template <typename T> T  Matrix<T>::get_item(const int n, const int m) {
  return this->Mat[n][m];
}
template <typename T> void Matrix<T>::set_value(const T &value, const int n, const int m) {
  this->Mat[n][m] = value;
}

template <typename T> void Matrix<T>::print() {

  std::cout << "[";
  for (int n = 0; n < this->rows(); n++) {
    std::cout << "[";
    for (int m = 0; m < this->columns(); m++) {
      std::cout << this->Mat.get_item(n, m) << ", ";
    }
    std::cout << "\b\b]\n";
  }
  std::cout << "\b]";
}


template <typename T> Matrix<T>::Matrix(const unsigned int N) {

// Constructs an Identity Matrix

      
  this->Mat.resize(N);
  for (int n = 0; n < N; n++) {
    this->Mat[n].resize(N, 0);
    this->set_value(1, n, n);
  }
}

template <typename T>
Matrix<T>::Matrix(const unsigned int N, const unsigned int M) {
// Constructs an Zero Matrix of size NxM
  this->Mat.resize(N);
  for (int n = 0; n < N; n++) {
    this->Mat[n].resize(M, 0);
  }
}

template <typename T> Matrix<T>::Matrix(const Matrix<T> &Mat) { this->Mat = Mat; }