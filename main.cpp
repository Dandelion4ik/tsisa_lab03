#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

double function_value(const double &x) { return -sqrt(x) * sin(x) + 2; }

double function_value_sin5x(const double &x) {
  return (-sqrt(x) * sin(x) + 2) * sin(5 * x);
}

bool probability(double &delta_fun, double &T_i) {
  std::random_device rd;
  return exp(-delta_fun / T_i) > (rd() % 10000) * 0.0001;
}

void print(const size_t &number, const double &T, const double &value,
           const double &fun_value) {
  std::cout << std::setw(3) << std::left << number << std::setw(10)
            << std::right << std::setprecision(5) << T << std::setw(10)
            << std::right << value << std::setw(12) << std::right << fun_value
            << std::endl;
}

void print_head() {
  std::cout << "N         T         x         f(x)" << std::endl;
}

int main() {
  std::random_device rd;
  const double T_min = 0.01;
  const double T_max = 10000;
  double T_i = T_max;
  double value = 0;
  double last_value = 0;
  double fun_val = 0;
  double fun_last_val = 100;
  print_head();
  size_t number = 1;
  while (T_i > T_min) {
    value = (rd() % 3001 + 1000) * 0.001;
    fun_val = function_value(value);
    if (fun_val - fun_last_val <= 0) {
      last_value = value;
      fun_last_val = fun_val;
    } else {
      double timeDelta = fun_val - fun_last_val;
      if (probability(timeDelta, T_i)) {
        last_value = value;
        fun_last_val = fun_val;
      }
    }
    print(number, T_i, last_value, fun_last_val);
    T_i *= 0.95;
    number++;
  }
  std::cout<<"Result: Xmin = "<<last_value+T_i/2<<"  Fmin = "<<fun_last_val;
  //////////////////////////////
  //////////////////////////////
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::random_device rd_f2;
  const double T_min_f2 = 0.01;
  const double T_max_f2 = 10000;
  double T_i_f2 = T_max_f2;
  double value_f2 = 0;
  double last_value_f2 = 0;
  double fun_val_f2 = 0;
  double fun_last_val_f2 = 100;
  print_head();
  size_t number_f2 = 1;
  while (T_i_f2 > T_min_f2) {
    value_f2 = (rd_f2() % 3001 + 1000) * 0.001;
    fun_val_f2 = function_value_sin5x(value_f2);
    if (fun_val_f2 - fun_last_val_f2 <= 0) {
      last_value_f2 = value_f2;
      fun_last_val_f2 = fun_val_f2;
    } else {
      double timeDelta = fun_val_f2 - fun_last_val_f2;
      if (probability(timeDelta, T_i_f2)) {
        last_value_f2 = value_f2;
        fun_last_val_f2 = fun_val_f2;
      }
    }
    print(number_f2, T_i_f2, last_value_f2, fun_last_val_f2);
    T_i_f2 *= 0.95;
    number_f2++;
  }
  std::cout<<"Result: Xmin = "<<last_value_f2+T_i_f2/2<<"  Fmin = "<<fun_last_val_f2;
  return 0;
}
