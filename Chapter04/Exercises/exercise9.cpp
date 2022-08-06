/*
   Exercise 9 on Page 129 (slightly modified)

   A program that essentialy calculates the sum of a geometric series
   This problem is combined with a story in the book, hence the specific values
   for a, r and n

   Using the sum of geometric series formula
   (an alternate (less efficient) solution would be to just add up using a loop
   until desired value)
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr double a = 1;
   constexpr double r = 2;
   constexpr double n = 64;

   // Using the sum of geometric series formula
   const double sum = a * (pow(r, n) - 1) / (r - 1);

   cout << sum << '\n';
}
