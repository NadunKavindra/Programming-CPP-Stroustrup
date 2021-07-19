/*
   Exercise 6 on Page 170

   Converts from Celcius to Fahrenheit and vice versa
*/

#include "../../std_lib_facilities.h"

double c_to_f(double c)
{
   constexpr double absolute_zero_c = -273.15;

   if (c < absolute_zero_c) {
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_c) + "\370C");
   }

   double k = c * (9.0 / 5) + 32;
   return k;
}

double f_to_c(double f)
{
   constexpr double absolute_zero_f = -459.67;

   if (f < absolute_zero_f)
      error("invalid argument, temperature cannot be below " + to_string(absolute_zero_f) + "\370F");

   double c = (f - 32) * (5.0 / 9);

   return c;
}

int main()
try {
   double celsius = 0;

   cout << "Enter value in celsius: ";
   cin >> celsius;

   double fahrenheit = c_to_f(celsius);
   cout << fahrenheit << "\370F" << '\n';

   cout << "Enter value in fahrenheit: ";
   cin >> fahrenheit;

   celsius = f_to_c(fahrenheit);
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
