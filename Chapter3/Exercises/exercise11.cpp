/*
   Solution for Exercise 11 Chapter 3 on Page 86-87
*/

#include "../../std_lib_facilities.h"

int main()
{
   int pennies = 0;
   cout << "How many pennies do you have ? ";
   cin >> pennies;

   int nickels = 0;
   cout << "How many nickels do you have ? ";
   cin >> nickels;

   int dimes = 0;
   cout << "How many dimes do you have ? ";
   cin >> dimes;

   int quarters = 0;
   cout << "How many quarters do you have ? ";
   cin >> quarters;

   int half_dollars = 0;
   cout << "How many half dollars do you have ? ";
   cin >> half_dollars;

   int one_dollars = 0;
   cout << "How many one-dollars do you have ? ";
   cin >> one_dollars;

   if (!cin) {
      simple_error("invalid input value");
   }

   cout << "\n\nYou have " << pennies << " pennie(s).\n";
   cout << "You have " << nickels << " nickel(s).\n";
   cout << "You have " << dimes << " dime(s).\n";
   cout << "You have " << quarters << " quarter(s).\n";
   cout << "You have " << half_dollars << " half dollar(s).\n";
   cout << "You have " << one_dollars << " one-dollar(s).\n";

   const int total_value = pennies + (5 * nickels) + (10 * dimes) + (25 * quarters)
                           + (50 * half_dollars) + (100 * one_dollars);

   const double dollars = total_value / 100.0;

   cout << "The value of all of your coins is $" << dollars << '\n';
}
