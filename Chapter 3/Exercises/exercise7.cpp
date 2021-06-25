/*
   Solution for Exercise 7 Chapter 3 on Page 86
   
   Prompts the user to enter three string values
   Outputs the values in alphabetical sequence seperated by commas
*/

#include "../../std_lib_facilities.h"

int main()
{
   string val1;
   string val2;
   string val3;

   cout << "Enter three strings seperated by a space: ";
   cin >> val1 >> val2 >> val3;

   string smallest;
   string largest;
   string middle;

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

   cout << "Strings in alphabetical sequence: " << smallest << ", " << middle << ", " << largest << '\n';
}
