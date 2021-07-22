/*
   Exercise 18 on Page 130

   Program that solves quadratic equations using real numbers
*/

#include "../../std_lib_facilities.h"

int main()
{
   double a = 0;
   double b = 0;
   double c = 0;

   cout << "A quadratic equation is of the form: ax^2 + bx + c = 0\n";
   cout << "Please enter the values of a, b and c (seperated by a space) of the equation you wish to solve: ";

   if (cin >> a >> b >> c) {
      const double discriminant = pow(b, 2) - 4 * a * c;

      if (discriminant < 0) {
         cout << "\nThis equation has no solution using real numbers.\n";
         exit(0);
      }

      const double x1 = (-1 * b + sqrt(discriminant)) / (2 * a);
      const double x2 = (-1 * b - sqrt(discriminant)) / (2 * a);

      cout << "x1 = " << x1 << '\n';
      cout << "x2 = " << x2 << '\n';
   }
   else
      simple_error("invalid input value");
}
