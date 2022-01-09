/*
   Exercise 3 on Page 169-170
   Converts celcius to kelvin
   Error produced inside main
*/

#include "../../std_lib_facilities.h"

double c_to_k(const double c)
{
   return c + 273.15;
}

int main()
{
   constexpr double absolute_zero = -273.15;

   cout << "Enter temperature in \370C: ";
   double c = 0;

   if (!(cin >> c)) {
      cerr << "Error: input value must be a number";
      return 1;
   }
   else if (c < absolute_zero) {
      cerr << "Error: temperature value must not be below " << absolute_zero
           << " \370C\n";
      return 1;
   }

   cout << c << " \370C == " << c_to_k(c) << " \370K" << '\n';
}
