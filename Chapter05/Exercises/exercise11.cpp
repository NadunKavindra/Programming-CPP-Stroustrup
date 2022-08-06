/*
   Exercise 11 on Page 171

   Writes out the values of the Fibonacci sequence
   Finds the largest fibonacci number that fits an int
   Assumes overflow occurs when a large number suddenly becomes negative
*/

#include "../../std_lib_facilities.h"

int main()
{
   int a = 0;
   int b = 1;

   while (b > 0) {
      cout << a << '\n';
      int c = b;
      b = a + b;
      a = c;
   }
   cout << "The largest fibonacci number that fits an int: " << a << '\n';
}
