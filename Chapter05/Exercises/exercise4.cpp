/*
   Exercise 4 on Page 169-170
   Converts celcius to kelvin
   Error produced inside function
*/

#include "../../std_lib_facilities.h"

double c_to_k(const double c)
{
   constexpr double absolute_zero = -273.15;

   if (c < absolute_zero) {
      error("invalid argument, temperature cannot be below "
            + to_string(absolute_zero) + " \370C");
   }

   return c + 273.15;
}

void run_exercise()
{
   cout << "Enter temperature in \370C: ";
   double c = 0;

   if (!(cin >> c)) {
      error("input value must be a number");
   }

   cout << c << " \370C == " << c_to_k(c) << " \370K" << '\n';
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
