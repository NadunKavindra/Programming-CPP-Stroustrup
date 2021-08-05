/*
   Solution for Exercise 5 Chapter 3 on Page 86

   Determines the smallest, difference, product and ratio
   of two floating-point values provided as input from the user
*/

#include "../../std_lib_facilities.h"

int main()
{
   double val1 {};
   double val2 {};

   cout << "Please enter a floating-point value: ";
   cin >> val1;

   cout << "Please enter another floating-point value: ";
   cin >> val2;

   if (val1 > val2)
      cout << val2 << " is the smaller value\n";
   else if (val2 > val1)
      cout << val1 << " is the smaller value\n";
   else
      cout << val1 << " == " << val2;

   cout << val1 << " - " << val2 << " == " << val1 - val2 << '\n';
   cout << val1 << " * " << val2 << " == " << val1 * val2 << '\n';
   cout << val1 << " / " << val2 << " == " << val1 / val2 << '\n';
}
