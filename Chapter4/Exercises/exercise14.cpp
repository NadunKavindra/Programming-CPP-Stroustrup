/*
   Exercise 14 on Page 130

   Program that finds all the prime numbers between 1 and user specified limit
   2 is considered to be the first prime
   Uses The Sieve of Eratosthenes
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int NOT_PRIME = 0;
   constexpr int PRIME = 1;
   constexpr int first_prime = 2;

   int max = 0;
   cout << "Please enter maximum value for the range (must be greater than 2): ";

   if (!(cin >> max && max > first_prime)) {
      simple_error("value must be an integer greater than "
                   + to_string(first_prime));
   }

   vector<int> numbers(100, 1);
   vector<int> primes;

   // Generate primes using The Sieve of Eratosthenes
   for (int i = first_prime; i < sqrt(max); ++i) {
      if (numbers[i] == PRIME) {
         primes.push_back(i);
         for (int j = static_cast<int>(pow(i, 2)); j < max; j += i) {
            numbers[j] = NOT_PRIME;
         }
      }
   }

   cout << "The prime numbers between 1 and " << max << ": ";
   for (int prime_num : primes) {
      cout << prime_num << ' ';
   }
   cout << '\n';
}
