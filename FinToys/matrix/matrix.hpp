#include <iostream>
#include <cmath>

template <typename T> class Matrix {
public:
  int get_rows(); //
  int get_columns(); //
  T get_item(const int n,const int m); // Get value, Index n by index m
  void set_value(const T &value, const int n, const int m); // Set value, Index n by index m

  // Constructor
  Matrix(const unsigned int N); // Identity
  Matrix(const unsigned int N, const unsigned int M); // Identity ? or zeros
  Matrix(const Matrix<T> &Mat); // copy constructor
  ~Matrix(); // Destructor

  // Operators
  Matrix<T>& operator+=(const Matrix<T> &rhs);
  Matrix<T>& operator-=(const Matrix<T> &rhs);
  Matrix<T>& operator*=(const Matrix<T> &rhs);
  Matrix<T>& operator/=(const Matrix<T> &rhs);

  Matrix<T>& operator+=(const T &rhs);
  Matrix<T>& operator-=(const T &rhs);
  Matrix<T>& operator*=(const T &rhs);
  Matrix<T> &operator/=(const T &rhs);
  
  // Print & Utils
  void print();

  // Linear Algebra
  T dot(const Matrix &rhs); // Dot product, inline with the instance as lhs
  Matrix<T> inv();
  void multiply(const Matrix &rhs); // Index wise multiplication
  void det(); // Determinant
  void transpose(); // Transpose

private:
  unsigned int rows(unsigned int n);
  unsigned int columns(unsigned int m);
  std::vector<std::vector<T> > Mat;
  
};