/*
   Solution for Exercise 11 Chapter 3 on Page 86-87
*/

#include "../../std_lib_facilities.h"

int main()
{
   int pennies = 0;
   int nickels = 0;
   int dimes = 0;
   int quarters = 0;
   int half_dollars = 0;
   int one_dollars = 0;

   cout << "How many pennies do you have ? ";
   cin >> pennies;

   cout << "How many nickels do you have ? ";
   cin >> nickels;

   cout << "How many dimes do you have ? ";
   cin >> dimes;

   cout << "How many quarters do you have ? ";
   cin >> quarters;

   cout << "How many half dollars do you have ? ";
   cin >> half_dollars;

   cout << "How many one-dollars do you have ? ";
   cin >> one_dollars;

   cout << "\n\nYou have " << pennies << " pennie(s).\n";
   cout << "You have " << nickels << " nickel(s).\n";
   cout << "You have " << dimes << " dime(s).\n";
   cout << "You have " << quarters << " quarter(s).\n";
   cout << "You have " << half_dollars << " half dollar(s).\n";
   cout << "You have " << one_dollars << " one-dollar(s).\n";

   int total_value = pennies + (5 * nickels) + (10 * dimes) + (25 * quarters)
                     + (50 * half_dollars) + (100 * one_dollars);

   int dollars = total_value / 100;
   int cents = total_value % 100;

   cout << "The value of all of your coins is $" << dollars << "." << cents << '\n';
}
