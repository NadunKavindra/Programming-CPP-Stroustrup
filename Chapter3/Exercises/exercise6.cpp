/*
   Solution for Exercise 6 Chapter 3 on Page 86

   Prompts the user to enter three integer values
   Outputs the values in numerical sequence seperated by commas
   (Purpose of exercise is to use nested if statements)
*/

#include "../../std_lib_facilities.h"

int main()
{
   int val1 = 0;
   int val2 = 0;
   int val3 = 0;

   cout << "Enter three integers values seperated by a space: ";
   cin >> val1 >> val2 >> val3;

   int smallest = 0;
   int largest = 0;
   int middle = 0;

   if (val1 > val2 && val1 > val3) {
      largest = val1;

      if (val2 > val3) {
         middle = val2;
         smallest = val3;
      }
      else {
         middle = val3;
         smallest = val2;
      }
   }
   else if (val2 > val1 && val2 > val3) {
      largest = val2;

      if (val1 > val3) {
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

      if (val1 > val2) {
         middle = val1;
         smallest = val2;
      }
      else {
         middle = val2;
         smallest = val1;
      }
   }

   cout << "Numbers in numerical sequence: " << smallest << ", " << middle
        << ", " << largest << '\n';
}
