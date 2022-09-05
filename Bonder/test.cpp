#include  <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

float e = M_E;
float pi = M_PI;
float x = 1;
using namespace std;

float PDF (float x, float sigma = 1, float mu = 0) {
  float level = (-1)*(pow(((x-mu)/sigma), 2)/2);
  float exponential = pow(e, level);
  float conjugate = 1/(sigma*(sqrt(2*pi)));
  float pdf = conjugate*exponential;
  return pdf;
}

float reserve(int precision) {
  /* Here we essentially need to solve Min = PDF(m), find m. Once this is found
  we can do a simple multiplication (yet to figure it out) of m to x for reserving the
  size of the array.*/
  float Min = precision + 0.01;
  float revX = 1;
  int size = 0;
  vector<int> vect2;
  while (Min > 1/(float)precision){
    size += 1;
    vect2.push_back(size);
    revX -= 1/(float)precision;
    Min = PDF(revX);

  }
  cout << size << endl;
  int reserve = (abs(x) - abs(revX)) / precision;
  //cout << "test: " << reserve << endl << "Min: " << vect2[-1] << endl;
  // for (int x : vect2)
  //   cout << x << " " << endl;
  return reserve;
}

float  CDF(float x, int precision){
  float prec = pow(10, precision);
  float Min = 1/prec;
  float  CDF = 0;
  for (float i = x; PDF(i) > Min; i = i-Min) {
    CDF += PDF(i)*Min;
  }
  cout << CDF << endl;
  return 0;
}


int main () {
  vector<int> vect;//add/push an integer to the end of the vector
  vect.push_back(10);//to traverse and print the vector from start to finish
  vect.push_back(9);
  // for (int x : vect)
  //   cout << x << " ";
  CDF(0.6, 4);
  return 0;
}
