#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>

const double PI = 3.1415923565;

// call: ./a.out NITER
int main(int argc, char **argv)
{
  const int NITER = std::atoi(argv[1]);
  const double R_log = 3;
  const double R_tent = 1.5;
  const double R_sin = 2;
  std::vector<double> x(NITER);
  std::vector<double> x_delta(NITER);
  std::vector<double> y(NITER);
  std::vector<double> y_delta(NITER);
  std::vector<double> z(NITER);
  std::vector<double> z_delta(NITER);

  x[0] = 0.12;
  for (int ii = 1; ii < NITER; ++ii) {
    x[ii] = R_log*x[ii-1]*(1-x[ii-1]);
  }
  x_delta[0] = 0.12 + 0.01;
  for (int ii = 1; ii < NITER; ++ii) {
    x_delta[ii] = R_log*x_delta[ii-1]*(1-x_delta[ii-1]);
  }

  y[0] = 0.012;
  for (int ii = 1; ii < NITER; ++ii) {
    if(y[ii] < 0.5){
      y[ii] = R_tent*y[ii-1];
    }
    else{
      y[ii] = R_tent*(1-y[ii-1]);
    }
  }
  y_delta[0] = 0.012 + 0.001;
  for (int ii = 1; ii < NITER; ++ii) {
    if(y_delta[ii] < 0.5){
      y_delta[ii] = R_tent*y_delta[ii-1];
    }
    else{
      y_delta[ii] = R_tent*(1-y_delta[ii-1]);
    }
  }

  z[0] = 0.12;
  for (int ii = 1; ii < NITER; ++ii) {
    z[ii] = R_sin*sin(PI*z[ii-1]);
  }

  z_delta[0] = 0.12 + 0.01;
  for (int ii = 1; ii < NITER; ++ii) {
    z_delta[ii] = R_sin*sin(PI*z_delta[ii-1]);
  }

  std::ofstream file1;
  file1.open("logistic.dat");
  std::ofstream file2;
  file2.open("tent.dat");
  std::ofstream file3;
  file3.open("sin.dat");

  for (int ii = 0; ii < NITER; ++ii) {
    file1 << ii << "  " << x[ii]<< "  " << x_delta[ii] << "\n";
    file2 << ii << "  " << y[ii]<< "  " << y_delta[ii] << "\n";
    file3 << ii << "  " << z[ii]<< "  " << z_delta[ii] << "\n";
  }

  file1.close();
  file2.close();
  file3.close();

  return 0;
}
