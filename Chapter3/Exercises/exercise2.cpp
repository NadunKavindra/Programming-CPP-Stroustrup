/*
   Solution for Exercise 1 Chapter 3 on Page 85

   Program that converts from miles to kilometers
*/

#include "../../std_lib_facilities.h"

int main()
{
   double miles = 0;

   cout << "Please enter number of miles: ";
   cin >> miles;

   if (miles < 0) {
      simple_error("distance cannot be a negative value");
   }

   double kilometers = miles * 1.609; // Approximate value

   cout << miles << " miles == " << kilometers << " kilometers\n";
}
