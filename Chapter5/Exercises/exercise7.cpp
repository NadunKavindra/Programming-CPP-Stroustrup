/*
   Exercise 7 on Page 170

   Program that solves quadratic equations using real numbers
   (Uses exceptions)
*/

#include "../../std_lib_facilities.h"

/// Returns a vector containing the roots of the equation
/// Throws an exception if a result cannot be found
vector<double> find_quadratic_roots(const double a, const double b, const double c)
{
   if (a == 0) {
      error("the value of 'a' must be positive!");
   }

   const double discriminant = pow(b, 2) - 4 * a * c;

   if (discriminant < 0) {
      error("This equation has no real roots");
   }

   const double x1 = (-1 * b + sqrt(discriminant)) / (2 * a);
   const double x2 = (-1 * b - sqrt(discriminant)) / (2 * a);

   return vector<double> {x1, x2};
}

void run_exercise()
{
   double a = 0;
   double b = 0;
   double c = 0;

   cout << "A quadratic equation is of the form: ax^2 + bx + c = 0\n";
   cout << "Please enter the values of a, b and c (seperated by a space) of the "
           "equation you wish to solve: ";

   if (!(cin >> a >> b >> c)) {
      error("invalid input values");
   }

   cout << "x1, x2 = ";
   for (double root : find_quadratic_roots(a, b, c)) {
      cout << root << ' ';
   }
   cout << '\n';
}

int main()
try {
   run_exercise();
   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception!\n";
   return 2;
}
