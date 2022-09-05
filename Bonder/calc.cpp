#define _USE_MATH_DEFINES

#include <ctime>
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;

float e = M_E;
float pi = M_PI;
class statModels{
  public: //type, precision, mu, sigma, x
    int type;
    int precision;
    float sigma, mu;
    float x;

    void set_values (int, int, float, float, float);

    float Normal (float n) {
      float level = (-1)*(pow(((n-this->mu)/this->sigma), 2)/2);
      float exponential = pow(M_E, level);
      float conjugate = 1/(this->sigma*(sqrt(2*M_PI)));
      float pdf = conjugate*exponential;
      return pdf;
    }
    float logNormal(float n){
      /* Call mu with 0, but let's keep a drift parameter in mind. This can then be
        implemented with a technical trading algorithm to find say momentum
        x will be the random parameter. Not sure how to implement randomness
        but it'll do for now
      */
      float exponential = pow(M_E, -pow((log1pf(n)-this->mu),2)/(2*pow(this->sigma,2)));
      float conjugate = 1/(n*this->sigma*(sqrt(2*pi)));
      float pdf = conjugate*exponential;
      return pdf;
    }

    float PDF(float n) {
      if (this->type == 0) {
        return this->Normal(n);
      } else if (this->type == 1){
        return this->logNormal(n);
      }
      return 0;
    }
    void values() {
      string TYPE;
      if (this->type == 0){
        TYPE = "Normal";
      } else if (this->type == 1){
        TYPE = "Log Normal";
      }
      cout << "Type: " << TYPE <<endl;
      cout << "Mu: " << this->mu << endl;
      cout << "Sigma: "  << this->sigma << endl;
    }

    float CDF() {
      /*
    The way the cdf works is that it takes in a PDF (probability distribution
    function) and it then integrates it. We can either feed it in a pretty
    integral or bruteforce your way through by looping it an insane amount
    of times and summing the PDF for say 2000 points depending on the precision.
    Need to check this efficiency. We can then store it in a pointer as an
    array of size precision. I will then use Python to visualize it and make
    sure I'm not doing any poopoo
    Edit: we're generalizing up to d1 and d2, which I'll write a function on
      */
      float prec = pow(10, -this->precision);
      float  CDF = 0;
      for (float i = this->x; PDF(i) > prec; i = i-prec) {
        CDF += PDF(i)*prec;
        cout << "PDF(" << i << ") = " << PDF(i) << endl;
      }
      //if (this->debug == 1) {
        cout << "CDF: " << CDF << endl;
      //}
      return CDF;
    }
};


/*
For d1 and d2, we'll take in strike price, spot, risk free rate and time to maturity. Those values should be global
for the calculations. As such, it is here where OOP becomes more interesting.
For the time being, we can instead create a getDs function outputting both.
*/
class blackScholes{
  public: //strike, spot, riskFree, ttm, sigma
    float strike, spot, riskFree, ttm, sigma, divYield;
    int debug;


    float getD1() {
      float first = log(this->spot / this->strike);
      float second = (this->riskFree + pow(this->sigma,2)/2)*this->ttm;
      float div = this->sigma*sqrt(this->ttm);
      float sum = first + second;
      float d1 = (log(this->spot/this->strike) + (this->riskFree - this->divYield + (pow(this->sigma,2)/2)*this->ttm))/(this->sigma*sqrt(this->ttm));
      return d1;
    }

    float getD2() {
      float d2 = this->getD1() - this->sigma*sqrt(this->ttm);
      return d2;
    }
    float callPrice() {
      /*
      First we need to get d1 and compute N(d1). We can store it in Nd1, we then need
      to update x to d2 and compute Nd2. Once we have all of those, our option price
      can be computed for European Calls
      */

      statModels statProfile;

      statProfile.type = 0; statProfile.precision = 3; statProfile.mu = 0; statProfile.sigma = this -> sigma;
      statProfile.x = this -> getD1();
      float Nd1 = statProfile.CDF();

      statProfile.x = this -> getD2();
      float Nd2 = statProfile.CDF();


      float callPrice = Nd1*this->spot*pow(M_E,(-1)*this->divYield*this->ttm) - Nd2*this->strike*pow(M_E,(this->riskFree*(-this->ttm)));
      if (this->debug == 1) {
        cout << "Test Nd1: " << Nd1 <<  endl;
        cout << "Test Nd2: " << Nd2 << endl;
      }
      return callPrice;
    }

    float putPrice() {
      statModels statProfile;
      statProfile.type = 0; statProfile.precision = 3; statProfile.mu = 0; statProfile.sigma = this -> sigma;

      statProfile.x = (1)*this->getD1();
      float Nd1 = statProfile.CDF();
      statProfile.x = (1)*this->getD2();
      float Nd2 = statProfile.CDF();

      float putPrice = (Nd2*this->strike*pow(M_E,((-1)*this->riskFree*this->ttm))) - (Nd1*this->spot*pow(M_E,(-1)*this->divYield*this->ttm));
      if (this-> debug == 1) {
        cout << "-D1: " << Nd1 << endl;
        cout << "-D2: " << Nd2 << endl;
      }
      return putPrice;
    }
    void printer() {
      //cout << "d1: " << this->getD1() << endl;
      //cout << "d2: " << this->getD2() << endl;
      cout << "Call Price: " << this->callPrice() << endl;
      cout << "Put Price: " << this->putPrice() << endl;
    }
};

class monteCarlo{
public:
  float A;
};

int  rand0to1 (int precision, int size) {
  float array [size];
  srand(time(NULL));
  for (int i = 0; i < size; i++ ){
    float x = (float)(rand() % precision) / precision;
    array[i] = x;
  }
  return 0;
}



int main() {
  std::time_t timeStamp = std::time(nullptr);
  //type, precision, mu, sigma, x -- statModels
  //strike, spot, riskFree, ttm, sigma -- blackScholes
  blackScholes New2;
  int debuger = 1;
  New2.strike = 10; New2.spot = 6; New2.riskFree = 0.06; New2.ttm = 1; New2.sigma = 0.01; New2.divYield = 0; New2.debug = debuger;
  //New2.getD1();
  //New2.getD2();
  New2.printer();
  // statModels New;
  // New.type = 0; New.precision = 3; New.mu = 0; New.sigma = 1; New.x = 0;
  // cout << New.CDF() << endl;
  // cout<< "Log(e) = "<<log(M_E) << endl;
  // New.values ();
  return 0;
}
