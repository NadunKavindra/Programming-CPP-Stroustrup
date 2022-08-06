/*
   Exercise 13 on Page 130

   Program that finds all the prime numbers between 1 and 100
   2 is considered to be the first prime
   Uses The Sieve of Eratosthenes
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int NOT_PRIME = 0;
   constexpr int PRIME = 1;

   constexpr int first_prime = 2;

   vector<int> numbers(100, 1);

   vector<int> primes;

   // Generate primes using The Sieve of Eratosthenes
   for (int i = first_prime; i < sqrt(100); ++i) {
      if (numbers[i] == PRIME) {
         primes.push_back(i);
         for (int j = static_cast<int>(pow(i, 2)); j < 100; j += i) {
            numbers[j] = NOT_PRIME;
         }
      }
   }

   cout << "The prime numbers between 1 and 100: ";
   for (int prime_num : primes) {
      cout << prime_num << ' ';
   }
   cout << '\n';
}
