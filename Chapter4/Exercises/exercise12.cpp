/*
   Exercise 12 on Page 130

   Program that finds all the prime numbers between 1 and user specified limit
   2 is considered to be the first prime
*/

#include "../../std_lib_facilities.h"

vector<int> primes { 2 };

bool is_prime(int number)
{
   for (int i { 0 }; i < primes.size(); ++i) {
      if (number % primes[i] == 0) {
         return false;
      }
   }
   return true;
}

int main()
{
   int max {};
   cout << "Please enter maximum value for the range (must be greater than 2): ";

   if (cin >> max && max > 2) {
      for (int i { 3 }; i < max; ++i) {
         if (is_prime(i)) {
            primes.push_back(i);
         }
      }

      cout << '\n' << "The prime numbers between 1 and " << max << " are:\n";

      for (int number : primes)
         cout << number << '\n';
   }
   else
      simple_error("value must be an integer greater than 2");
}
