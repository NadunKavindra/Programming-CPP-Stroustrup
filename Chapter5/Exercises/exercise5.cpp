/*
   Exercise 5 on Page 169-170
   Converts celsius to kelvin
*/

#include "../../std_lib_facilities.h"



double c_to_k(double c)
{
   constexpr double absolute_zero_c = -273.15;

   if (c < absolute_zero_c) {
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_c) + "\370C");
   }

   double k = c + 273.15;
   return k;
}

double k_to_c(double k)
{
   constexpr double absolute_zero_k = 0;

   if (k < absolute_zero_k)
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_k) + "\370K");

   double c = k - 273.15;
   return c;
}

int main()
try {
   double celsius = 0;

   cout << "Enter value in celsius: ";
   cin >> celsius;

   double kelvin = c_to_k(celsius);
   cout << kelvin << "\370K" << '\n';

   cout << "Enter value in kelvin: ";
   cin >> kelvin;

   celsius = k_to_c(kelvin);
   cout << celsius << "\370C" << '\n';

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
