/*
   Exercise 11 on Page 129

   Program that finds all the prime numbers between 1 and 100
   2 is considered to be the first prime
*/

#include "../../std_lib_facilities.h"

vector<int> primes = { 2 };

bool is_prime(int number)
{
   for (int i = 0; i < primes.size(); ++i)
      if (number % primes[i] == 0)
         return false;

   return true;
}

int main()
{
   for (int i = 3; i < 100; ++i)
      if (is_prime(i))
         primes.push_back(i);

   cout << "The prime numbers between 1 and 100 are:\n";

   for (int number : primes)
      cout << number << ' ';
   
   cout << '\n';
}
