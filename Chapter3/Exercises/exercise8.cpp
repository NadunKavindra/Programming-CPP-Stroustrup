/*
   Solution for Exercise 8 Chapter 3 on Page 86

   Determines wheter an integer value is even or odd
*/

#include "../../std_lib_facilities.h"

int main()
{
   int val = 0;
   cout << "Please enter an integer value: ";
   cin >> val;

   if (val % 2 == 0) {
      cout << "The value " << val << " is an even number\n";
   }
   else {
      cout << "The value " << val << " is an odd number\n";
   }
}
