/*
   Solution for Exercise 6 Chapter 3 on Page 86

   Prompts the user to enter three integer values
   Outputs the values in numerical sequence seperated by commas
   (Not the most elegant solution without the use of a vector, not introduced in the book yet)
*/

#include "../../std_lib_facilities.h"

int main()
{
   int val1 {};
   int val2 {};
   int val3 {};

   cout << "Enter three integers values seperated by a space: ";
   cin >> val1 >> val2 >> val3;

   int smallest {};
   int largest {};
   int middle {};

   if (val1 >= val2 && val1 >= val3) {
      largest = val1;

      if (val2 >= val3) {
         middle = val2;
         smallest = val3;
      }
      else {
         middle = val3;
         smallest = val2;
      }
   }
   else if (val2 >= val1 && val2 >= val3) {
      largest = val2;

      if (val1 >= val3) {
         middle = val1;
         smallest = val3;
      }
      else {
         middle = val3;
         smallest = val1;
      }
   }
   else {
      largest = val3;

      if (val1 >= val2) {
         middle = val1;
         smallest = val2;
      }
      else {
         middle = val2;
         smallest = val1;
      }
   }

   cout << "Numbers in numerical sequence: " << smallest << ", " << middle << ", " << largest << '\n';
}
