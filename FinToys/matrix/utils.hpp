#include "header.h"
#include "matrix.hpp"

template <typename T> std::vector<double> linspace(const T &start, const T &end);
template <typename T>
std::vector<double> linspace(const T &start, const T &end, size_t size);

// Linear algebra
template <typename T>
Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs); // piece wise addition
template <typename T>
Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs); // piece wise subtraction
template <typename T>
Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs); // piece wise multiplication

template <typename T> Matrix<T> dot(const Matrix<T> &lhs, const Matrix<T> &rhs);

// Scalar operations
template <typename T> Matrix<T> operator+(const T &scalar, const Matrix<T> &rhs);
template <typename T> Matrix<T> operator-(const T &scalar, const Matrix<T> &rhs);
template <typename T> Matrix<T> operator*(const T&scalar, const Matrix<T> &rhs);

// Initialization
Matrix<double> ones(const unsigned int N, const unsigned int M);
Matrix<double> zeros(const unsigned int N, const unsigned int M);
Matrix<double> identity(const unsigned int N, const unsigned int M);