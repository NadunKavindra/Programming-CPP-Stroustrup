/*
     Chapter 9 Exercise 13 on Page 340
     Implementing a rational number class
 */

#include "Rational.h"
#include <iostream>

using std::cerr;
using std::cout;

int main()
try {
   Rational r1{4, 5};
   cout << "r1 == " << r1.to_double() << '\n';

   Rational r2{3, 5}; // Should throw an exception
   cout << "r2 == " << r2.to_double() << '\n';

   cout << '\n';

   cout << "r1 + r2 == " << (r1 + r2).to_double() << '\n';
   cout << "r1 - r2 == " << (r1 - r2).to_double() << '\n';
   cout << "r1 * r2 == " << (r1 * r2).to_double() << '\n';
   cout << "r1 / r2 == " << (r1 / r2).to_double() << '\n';
   cout << "r1 == r2 ? " << (r1 == r2) << '\n';

   cout << '\n';

   Rational r3{2, 5};
   cout << "r3 == " << r3.to_double() << '\n';

   r1 = r3;
   cout << "r1 == " << r1.to_double() << '\n';
   cout << "r1 == r3 ? " << (r1 == r3) << '\n';

   return 0;
}
catch (const std::exception& exception) {
   cerr << "Error: " << exception.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
