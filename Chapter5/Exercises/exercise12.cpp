/*
   Exercise 12 on Page 171

   A guessing game called "Bulls and Cows"
   The program contains a vector of four different numbers in the range 0-9
   It is the user's task to discover these numbers by repeated guesses

   I found the solution of splitting a string to get the individual digits (as chars)
   simpler than using ints Also, using chars means that the program can be easily
   modified for guessing 4 letter words instead of numbers
*/

#include "../../std_lib_facilities.h"

int main()
{
   // would be better to fill the vector randomly but randomness not yet introduced
   // in the book
   const vector<char> answer {'1', '2', '3', '4'};

   string user_guess;

   cout << "Please make a guess (must be a " << answer.size() << " digit number): ";
   while (cin >> user_guess) {
      int bulls = 0; // the number of guesses that got post position and value right
      int cows = 0;  // the number of guesses that only got the value right

      if (user_guess.length() > answer.size()) {
         cerr << "Input must have a length of " << answer.size()
              << ". Please try again: ";
         continue;
      }

      for (size_t i = 0; i < answer.size(); ++i) {
         // both correct digit and position
         if (user_guess[i] == answer[i]) {
            ++bulls;
         }
         // just correct digit
         else if (find(answer.begin(), answer.end(), user_guess[i])
                  != answer.end()) {
            ++cows;
         }
      }

      if (static_cast<size_t>(bulls) == answer.size()) {
         cout << "Congratulations! You have found the answer...\n";
         return 0;
      }

      cout << bulls << " bull(s) and " << cows << " cow(s)\n\n";
      cout << "Guess again: ";
   }
}