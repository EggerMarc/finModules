#include "utils.hpp"

template <typename T>
std::vector<double> linspace(T &start, T &end, size_t size) {
  std::vector<double> vec(size);

  for (int i = 0; i < size; ++i) {
    vec[i] = start + static_cast<double>(i) * (end - start) /
                            static_cast<double>(size - 1); // Inspired by matplot++
  }
  return vec;
}
template <typename T> std::vector<double> linspace(T &start,T &end) {
return linspace(start, end, 50);
}

template <typename T> int get_Hash(T &value) {

  std::hash<T> hash;
  
  return hash(value);
}

template <typename T> void printl(T list[], size_t size) {
  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << list[i] << ", ";
  }
  std::cout << "\b\b]" << std::endl;
}

template <typename T> void printv(std::vector<T> vec) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ", ";
  }
  std::cout << "\b\b]" << std::endl;
}

template <typename T> void printm(Matrix<T> mat) {
  unsigned int N = mat.row();
  unsigned int M = mat.col();

  std::cout << "[";
  for (int n = 0; n < N; n++) {
    std::cout << "[";
    for (int m = 0; m < M; m++) {
      std::cout << mat.get_item(n, m) << ", ";
    }
    std::cout << "\b\b]\n";
  }
  std::cout << "\b]";
}

template <typename T>
bool broadcast(const Matrix<T> &lhs, const Matrix<T> &rhs) {
    if (lhs.col != rhs.row) {
    std::cout << "Unable to broadcast shapes, (" << lhs.row << ", " << lhs.col
              << ")x(" << rhs.row << ", " << rhs.col << ")." << std::endl;
    
    return false;
    } else {
      return true;
    }
}

// Piece wise operations

template <typename T> Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs) {
  if (!broadcast(lhs, rhs)) {
      return;
  }

  int N = lhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs.get_value(n,m) + rhs.get_value(n,m)), n, m);
    }
  }

  return mat;
};

template <typename T> Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {
  if (!broadcast(lhs, rhs)) {
      return;
  }

  int N = lhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs.get_value(n,m) - rhs.get_value(n,m)), n, m);
    }
  }

  return mat;
};

template <typename T> Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
  if (!broadcast(lhs, rhs)) {
      return;
  }

  int N = lhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs.get_value(n,m) * rhs.get_value(n,m)), n, m);
    }
  }
  return mat;
};

// Scalar operations
template <typename T> Matrix<T> operator+(const T &lhs, const Matrix<T> &rhs) {

  int N = rhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs + rhs.get_value(n,m)), n, m);
    }
  }

  return mat;
};

template <typename T> Matrix<T> operator-(const T &lhs, const Matrix<T> &rhs) {

  int N = rhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs + rhs.get_value(n,m)), n, m);
    }
  }

  return mat;
};

template <typename T> Matrix<T> operator*(const T &lhs, const Matrix<T> &rhs) {

  int N = rhs.row;
  int M = rhs.col;
  Matrix<T> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((lhs + rhs.get_value(n,m)), n, m);
    }
  }

  return mat;
};

// Initialization
Matrix<double> ones(const unsigned int &N, const unsigned int &M) {

  Matrix<double> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value(1, n, m);
    }
  }

  return mat;
};

Matrix<double> zeros(const unsigned int &N, const unsigned int &M) {

  Matrix<double> mat(N, M);
  return mat;
};

Matrix<double> identity(const unsigned int &N, const unsigned int &M) {

  Matrix<double> mat(N, M);

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      mat.set_value((n == m ? 1 : 0), n, m);
    }
  }

  return mat;
};


void printl_test() {
  std::string list_of_names[4] = {"John Smith", "Lisa Smith", "Sam Doe",
                                  "Sandra Dee"};
  int list_of_numbers[4] = {1, 26, 4, 3};

  //printl(list_of_names, len(list_of_names));
  //printl(list_of_numbers, len(list_of_numbers));

  int hashed_names[4];
  int hashed_numbers[4];
  
  for (int i = 0; i < len(list_of_names); i++) {
    hashed_names[i] = get_Hash(list_of_names[i]);
  }
  for (int i = 0; i < len(list_of_numbers); i++) {
    hashed_numbers[i] = get_Hash(list_of_numbers[i]);
  }

  //printl(hashed_names, len(hashed_names));
  //printl(hashed_numbers, len(hashed_numbers));
}

void linspace_test() {
  int start = 0;
  int end = -10;
  std::cout << linspace(start, end).size() << '\n';
  printv(linspace(start,end));
}

int main() {
 linspace_test();
  // std::pair<double, double> list_of_pairs[2] = {{2.3, 1.2}, {0.1, 7.8}};
  return 0;
}