/*
   Exercise 13 on Page 130

   Program that finds all the prime numbers between 1 and 100
   2 is considered to be the first prime
   Uses The Sieve of Eratosthenes
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int not_prime { 0 };
   constexpr int is_prime { 1 };

   constexpr int first_prime { 2 };

   vector<int> numbers(100, 1);

   for (int i { first_prime }; i < sqrt(100); ++i) {
      if (numbers[i] == is_prime) {
         for (int j = pow(i, 2); j < 100; j += i) {
            numbers[j] = not_prime;
         }
      }
   }

   cout << "The prime numbers between 1 and 100: ";

   for (int i { first_prime }; i < numbers.size(); ++i) {
      if (numbers[i] == is_prime) {
         cout << i << ' ';
      }
   }
   cout << '\n';
}
