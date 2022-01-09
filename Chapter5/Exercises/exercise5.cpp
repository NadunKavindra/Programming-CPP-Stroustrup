/*
   Exercise 5 on Page 169-170
   Converts celsius to kelvin and vice versa
*/

#include "../../std_lib_facilities.h"

double c_to_k(const double c)
{
   constexpr double absolute_zero_c = -273.15;

   if (c < absolute_zero_c) {
      error("invalid argument, temperature cannot be below "
            + to_string(absolute_zero_c) + " \370C");
   }

   return c + 273.15;
}

double k_to_c(const double k)
{
   constexpr double absolute_zero_k = 0;

   if (k < absolute_zero_k) {
      error("invalid argument, temperature cannot be below "
            + to_string(absolute_zero_k) + " \370K");
   }

   return k - 273.15;
}

void run_exercise()
{
   double celsius = 0;
   cout << "Enter temperature in \370C: ";

   if (!(cin >> celsius)) {
      error("input value must be a number");
   }

   cout << celsius << " \370C == " << c_to_k(celsius) << " \370K"
        << "\n\n";

   double kelvin = 0;
   cout << "Enter temperature in \370K: ";

   if (!(cin >> kelvin)) {
      error("input value must be a number");
   }

   cout << kelvin << " \370K == " << k_to_c(kelvin) << " \370C" << '\n';
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
