/*
   Exercise 14 on Page 130

   Program that finds all the prime numbers between 1 and user specified limit
   2 is considered to be the first prime
   Uses The Sieve of Eratosthenes
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int not_prime = 0;
   constexpr int is_prime = 1;
   constexpr int first_prime = 2;

   int max = 0;

   cout << "Please enter maximum value for the range: ";

   if (cin >> max && max > first_prime) {
      vector<int> numbers(max, 1);

      for (int i = first_prime; i < sqrt(max); ++i) {
         if (numbers[i] == is_prime) {
            for (int j = pow(i, 2); j < max; j += i)
               numbers[j] = not_prime;
         }
      }

      cout << '\n' << "The prime numbers between 1 and " << max << ":\n";

      for (int i = first_prime; i < numbers.size(); ++i)
         if (numbers[i] == is_prime)
            cout << i << '\n';
   }
   else
      simple_error("value must be an integer greater than " + to_string(first_prime));
}
