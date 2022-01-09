/*
   Exercise 6 on Page 170

   Converts from Celcius to Fahrenheit and vice versa
*/

#include "../../std_lib_facilities.h"

double c_to_f(const double c)
{
   constexpr double absolute_zero_c = -273.15;

   if (c < absolute_zero_c) {
      error("invalid argument, temperature cannot be below "
            + to_string(absolute_zero_c) + "\370C");
   }

   return c * (9.0 / 5) + 32;
}

double f_to_c(const double f)
{
   constexpr double absolute_zero_f = -459.67;

   if (f < absolute_zero_f) {
      error("invalid argument, temperature cannot be below "
            + to_string(absolute_zero_f) + "\370F");
   }

   return (f - 32) * (5.0 / 9);
}

void run_exercise()
{
   double celsius = 0;
   cout << "Enter temperature in \370C: ";

   if (!(cin >> celsius)) {
      error("input value must be a number");
   }

   cout << celsius << " \370C == " << c_to_f(celsius) << " \370F"
        << "\n\n";

   double fahrenheit = 0;
   cout << "Enter temperature in \370F: ";

   if (!(cin >> fahrenheit)) {
      error("input value must be a number");
   }

   cout << fahrenheit << " \370F == " << f_to_c(fahrenheit) << " \370C" << '\n';
}

int main()
try {
   run_exercise();
   return 0;
}
catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
