#pragma once
#include "header.h"

class Underlying {
public:
  Underlying(double volatility, double S0, double q) {
    _volatility = volatility, _S0 = S0, _q = q;
  };

protected:
  double _volatility; // Annualized Volatility
  double _S0;         // Starting Value
  double _q;          // Continuously compounded dividend rate
};

class Stock : public Underlying {
public:
  Stock(double volatility, double S0, double q)
      : Underlying{_volatility = volatility, _S0 = S0, _q = q} {};
  std::vector<double> __s();
};

class Fixed : Underlying {
public:
  Fixed(double _volatility, double _S0, double _q)
      : Underlying{_volatility, _S0, _q} {};
  std::vector<double> __s();
  std::vector<double> __xs();
};