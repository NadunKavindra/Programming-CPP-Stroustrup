/*
   Exercise 4 on Page 169-170
   Converts celcius to kelvin
*/

#include "../../std_lib_facilities.h"

double c_to_k(double c)
{
   constexpr double absolute_zero = -273.15;

   if (c < absolute_zero) {
      error("invalid argument, temperature value cannot be below " + to_string(absolute_zero));
   }

   double k = c + 273.15;
   return k;
}

int main()
try {
   constexpr double absolute_zero = -273.15;
   double c = 0;
   cin >> c;
   
   double k = c_to_k(c);
   cout << k << '\n';
   
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
