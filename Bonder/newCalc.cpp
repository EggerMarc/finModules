#include <iostream>
#include <cmath>

class statModels {
private:
  float CDF(), PDF();
  float Normal(), logNormal();

public:
  unsigned model, debug;
  float sigma, mu, precision, x;
  float output();
  statModels()
    : sigma(1), mu(0.06), x(-0.950826), precision(5), model(0),debug(0)

  {
    int debug2 = 1;
    if (debug2 ==1) {
      std::cout << "x: " << x << std::endl;
      std::cout << "Sigma: " << sigma << std::endl;
      std::cout << "Mu: " << mu << std::endl;
      std::cout << "PDF: " << PDF() << std::endl;
      std::cout << "CDF: " << CDF() << std::endl;
    }
  }

  statModels(const float& sigma, const float& mu,const float& x, const int& precision, const unsigned& model)
    : sigma(sigma), mu(mu), x(x), precision(precision), model(model), debug(0)
  {
    CDF();
  }
};

float statModels::Normal(){
  return pow(M_E,(-0.5)*pow((x - mu)/sigma, 2))/(sigma*(sqrt(2*M_PI)));
}

float statModels::logNormal(){
  return 1.0;
}

float statModels::PDF(){
  if (model == 0) {
    return Normal();
  }
  else if (model == 1) {
    return logNormal();
  }
  return 0;
}

float statModels::output(){
  int debug2 = 1;
  if (debug2 ==1) {
    std::cout << "x: " << x << std::endl;
    std::cout << "Sigma: " << sigma << std::endl;
    std::cout << "Mu: " << mu << std::endl;
    std::cout << "Precision: " << precision << std::endl;
    std::cout << "PDF: " << PDF() << std::endl;
    std::cout << "CDF: " << CDF() << std::endl;
  }
  return CDF();
}
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
float statModels::CDF() {
  float prec = pow(10,-precision);
  float val = 0;
  debug = 0;
  for (float i = x; PDF() > prec; i = i - prec){
    x = i; //update x
    val += PDF()*prec;
  }
  if (debug == 1) {
    std::cout<< "Initializing" << std::endl;
    std::cout <<" x: "<< x << std::endl;
    std::cout << "PDF(): " << PDF() << std::endl;
    std::cout << "Precision: " << prec << std::endl;
    std::cout << "CDF: "<< val << std::endl;
  }
  return val;
}


class calculator{
private:
  float D_J();

  float Put();
  float Call();

public:
  float strike,spot, volatility, ttm, riskFree;
  float D_Type;
  calculator()
    :strike(10),spot(6),volatility(1),ttm(1),riskFree(0.06),D_Type()
    {
      std::cout << Call() << std::endl;
    }

};

float calculator::D_J(){
  return (log(spot/strike)+(riskFree + pow(-1,D_Type - 1)*0.5*volatility*volatility*ttm))/(volatility*pow(ttm,0.5));
}

float calculator::Call(){
  int precision = 4;
  unsigned model = 0;

  D_Type = 1; float D_1 = D_J();
  D_Type = 2; float D_2 = D_J();
  //std::cout  << "D_1: " << D_1 << std::endl;
  //std::cout  << "D_2: " << D_2 << std::endl;
  float trial = 0.5;
  statModels cdfD1(volatility,riskFree,trial,precision,model);
  D_1 = cdfD1.output();
  statModels cdfD2(volatility,riskFree,D_2,precision,model);
  D_2 = cdfD2.output();
  //std::cout << "ND_1: " << D_1 << std::endl;
  //std::cout << "ND_2: " << D_2 << std::endl;
  return spot*D_1 - strike*pow(M_E,-riskFree*ttm)*D_2;
}

float calculator::Put(){
  return 1.0;
}

int main(){
  calculator trial;
  statModels trial2;
  //float sg =1, m = 0, xVal = 0;
  //int pr = 4;
  //unsigned md = 0;
  //statModels trial(sg,m,xVal,pr, md);
  // trial.sigma = 1; trial.mu = 0; trial.debug = 1; trial.model = 0;
  std::cin.get();
  // std::cout << trial << std::endl;
};
