/*
   Exercise 5 on Page 169-170
   Converts celsius to kelvin and vice versa
*/

#include "../../std_lib_facilities.h"

double c_to_k(const double c)
{
   constexpr double absolute_zero_c { -273.15 };

   if (c < absolute_zero_c) {
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_c) + " \370C");
   }

   return c + 273.15;
}

double k_to_c(const double k)
{
   constexpr double absolute_zero_k { 0 };

   if (k < absolute_zero_k) {
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_k) + " \370K");
   }

   return k - 273.15;
}

int main()
try {
   double celsius {};
   cout << "Enter temperature in \370C: ";
   cin >> celsius;

   if (!cin) {
      error("input value must be a number");
   }

   cout << celsius << " \370C == " << c_to_k(celsius) << " \370K" << "\n\n";

   double kelvin {};
   cout << "Enter temperature in \370K: ";
   cin >> kelvin;

   if (!cin) {
      error("input value must be a number");
   }

   cout << kelvin << " \370K == " << k_to_c(kelvin) << " \370C" << '\n';
}
catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
