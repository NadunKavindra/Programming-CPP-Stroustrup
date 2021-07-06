/*
   Exercise 8 on Page 129

   A program that essentially calculates the value of n given the sum of a geometric series.
   This problem is combined with a story in the book, hence the specific values for a, r, n 
   and the rice "grains". 

   Using formula for sum of geometric series
   (an alternate solution would be to just add up using a loop until desired value)
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int a = 1;
   constexpr int r = 2;
   int n = 0;

   const vector<double> grain_limits = { 1e3, 1e6, 1e9 };

   for (int grains : grain_limits) {
      n = ceil((log(1 + grains * (r - 1)) / a) / log(r));
      cout << n << " squares are required for " << grains << " grains of rice\n";
   }
}
