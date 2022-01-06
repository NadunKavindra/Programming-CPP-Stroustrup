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
   constexpr int NOT_PRIME = 0;
   constexpr int PRIME = 1;
   constexpr int first_prime = 2;

   // a large number to ensure enough primes are generated
   constexpr int BIG_NUMBER = 100000;

   // there are only 9592 prime numbers from 2 to 100000
   constexpr int N_LIMIT = 9592;

   int n = 0;
   cout << "Enter the number of prime numbers to be found: ";

   if (!(cin >> n) || n > N_LIMIT || n <= 0) {
      simple_error("input value must be a positive integer."
                   "This program can only display the first 9592 primes");
   }

   vector<int> numbers(BIG_NUMBER, 1);
   vector<int> primes;

   // Generate primes using The Sieve of Eratosthenes
   for (int i = first_prime; i < sqrt(BIG_NUMBER); ++i) {
      if (numbers[i] == PRIME) {
         primes.push_back(i);

         if (primes.size() == static_cast<size_t>(n)) {
            break;
         }

         for (int j = static_cast<int>(pow(i, 2)); j < BIG_NUMBER; j += i) {
            numbers[j] = NOT_PRIME;
         }
      }
   }
   cout << "The first " << n << " prime numbers are:\n";

   for (int prime_num : primes) {
      cout << prime_num << ' ';
   }
   cout << '\n';
}