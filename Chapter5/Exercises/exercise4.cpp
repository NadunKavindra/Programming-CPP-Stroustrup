/*
   Exercise 4 on Page 169-170
   Converts celcius to kelvin
   Error produced inside function
*/

#include "../../std_lib_facilities.h"

double c_to_k(const double c)
{
   constexpr double absolute_zero { -273.15 };

   if (c < absolute_zero) {
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero) + " \370C");
   }

   return c + 273.15;
}

int main()
try {
   cout << "Enter temperature in \370C: ";
   double c {};
   cin >> c;

   if (!cin) {
      error("input value must be a number");
   }

   cout << c << " \370C == " << c_to_k(c) << " \370K" << '\n';
}
catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
