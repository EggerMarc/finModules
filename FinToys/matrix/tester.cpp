#include <iostream>
#include <vector>
//#include "matrix.cpp"
//#include "utils.cpp"

template <typename T> class Matrix {
private:
  unsigned int rows;
  unsigned int cols;
  std::vector<std::vector<T> > Mat;

public:
  Matrix<T> operator()(unsigned int N, unsigned int M) {
    return this->Mat[N][M];
}
  Matrix<T>(const unsigned int N) {
    this->rows = N;
    this->cols = N;
    this->Mat.resize(N);
    for (int n = 0; n < N; n++) {
      this->Mat[n].resize(N, 0);
    }
  }
  Matrix<T>(const unsigned int N, const unsigned int M) {
    this->rows = N;
    this->cols = M;
    this->Mat.resize(N);
    for (int n = 0; n < N; n++) {
      this->Mat[n].resize(M, 0);
    }
  }

  ~Matrix<T>() {}

  void print() {
    std::cout << "[";
    for (int n = 0; n < this->rows; n++) {
      std::cout << "[";
      for (int m = 0; m < this->cols; m++) {
        std::cout << this->Mat[n][m] << ", ";
      }
      std::cout << "\b\b]\n";
    }
    std::cout << "\a]" << std::endl;
  }

};

int main() {

  std::vector<std::vector<int> > vect{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  
  
  for (int i = 0; i < vect.size(); i++) {
    for (int j = 0; j < vect[i].size(); j++) {
        std::cout << vect[i][j] << ", ";
    }
    std::cout << "\n";
  }

  std::cout << "Onto tests: " << std::endl;
  Matrix<double> M(10);
  M.print();

  std::cout << std::endl;
  Matrix<double> B(4, 2);
  B.print();
  
  return 0;
}