/*
   Exercise 3 on Page 169-170
   Converts celcius to kelvin
*/

#include "../../std_lib_facilities.h"

double c_to_k(double c)
{
   double k = c + 273.15;
   return k;
}

int main()
{
   constexpr double absolute_zero = -273.15;

   double c = 0;
   cin >> c;

   if (c < absolute_zero) {
      cerr << "Error:temperature value must not be below " << absolute_zero << " celcius\n";
      return 1;
   }

   double k = c_to_k(c);
   cout << k << '\n';
}
