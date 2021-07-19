/*
   Exercise 7 on Page 170

   Program that solves quadratic equations using real numbers
   (Uses exceptions)
*/

#include "../../std_lib_facilities.h"

// Prints out the roots of a quadratic equation
void find_quadratic_roots(double a, double b, double c)
{
   if (a == 0)
      error("the value of 'a' must be positive!");

   const double discriminant = pow(b, 2) - 4 * a * c;

   if (discriminant < 0) {
      cout << "\nThis equation has no roots that are real numbers.\n";
      return;
   }

   const double x1 = (-1 * b + sqrt(discriminant)) / (2 * a);
   const double x2 = (-1 * b - sqrt(discriminant)) / (2 * a);

   cout << "x1 = " << x1 << '\n';
   cout << "x2 = " << x2 << '\n';
}

int main()
try {
   double a = 0;
   double b = 0;
   double c = 0;

   cout << "A quadratic equation is of the form: ax^2 + bx + c = 0\n";
   cout << "Please enter the values of a, b and c (seperated by a space) of the equation you wish to solve: ";

   if (cin >> a >> b >> c)
      find_quadratic_roots(a, b, c);
   else {
      cerr << "Error: invalid input values\n";
      return 1;
   }
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
