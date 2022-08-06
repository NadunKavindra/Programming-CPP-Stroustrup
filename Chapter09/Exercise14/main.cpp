/*
Chapter 9 Exercise 14 Page 341
Implementing a simple Money class involving dollars and cents
*/

#include "Money.h"
#include <exception>
#include <iostream>

int main()
try {
   Money test{1};
   Money test2{655, 99};

   std::cout << test2 << '\n';
   std::cout << test << '\n';
   std::cout << "Addition: " << test + test2 << '\n';
   std::cout << "Subtraction: " << test2 - test << '\n';
   return 0;
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Oops: unknown exception\n";
   return 2;
}
