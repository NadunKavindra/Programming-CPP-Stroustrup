/*
   Exercise 15 on Page 130

   Takes an input value n
   Finds the first n prime numbers
   2 is considered to be the first prime
   Uses The Sieve of Eratosthenes
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int not_prime { 0 };
   constexpr int is_prime { 1 };
   constexpr int first_prime { 2 };
   constexpr int big_number { 100000 };   // a large number to ensure enough primes are generated
   constexpr int n_limit { 9592 };        // there are only 9592 prime numbers from 2 to 100000

   vector<int> numbers(big_number, 1);

   int n {};
   cout << "Enter the number of prime numbers to be found: ";
   cin >> n;

   if (!cin || n < 1) {
      simple_error("input value must be a positive integer");
   }
   else if (n > n_limit) {
      simple_error("This program can only display the first 9592 primes");
   }

   // generate primes
   for (int i { first_prime }; i < sqrt(big_number); ++i) {
      if (numbers[i] == is_prime) {
         for (int j = pow(i, 2); j < big_number; j += i)
            numbers[j] = not_prime;
      }
   }

   cout << "The first " << n << " prime numbers are:\n" ;

   for (int i { first_prime }; n != 0; ++i) {
      if (numbers[i] == is_prime) {
         cout << i << '\n';
         --n;
      }
   }
}