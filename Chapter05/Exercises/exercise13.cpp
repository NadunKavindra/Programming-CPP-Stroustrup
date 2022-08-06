/*
   Exercise 13 on Page 171

   A guessing game called "Bulls and Cows"
   The program contains a vector of four different numbers in the range 0-9
   It is the user's task to discover these numbers by repeated guesses

   Modified version of Exercise 12 that uses randomness.

   I found the solution of splitting a string to get the individual digits (as chars) simpler than using ints
   Also using chars means that the program can be easily modified for guessing 4 letter words instead of numbers
*/

#include "../../std_lib_facilities.h"

int main()
{
   constexpr int answer_length = 4;
   vector<char> answer;

   for (int i = 0; i < answer_length; ++i) {
      char c = static_cast<char>(randint(9) + 48); // ASCI digits start at code 48
      answer.push_back(c);
   }

   for (char c : answer) {
      cout << c;
   }

   string user_guess;

   cout << "\nPlease make a guess (must be a " << answer_length << " digit number): ";
   while (cin >> user_guess) {
      int bulls = 0;  // the number of guesses that got post position and value right
      int cows = 0;   // the number of guesses that only got the value right

      if (user_guess.length() > answer_length) {
         cerr << "Input must have a length of " << answer_length << ". Please try again: ";
         continue;
      }

      for (int i = 0; i < answer_length; ++i) {
         // guessed both correct digit and position
         if (user_guess[i] == answer[i]) {
            ++bulls;
         }
         else if (find(answer.begin()+i, answer.end(), user_guess[i]) != answer.end()) {
            ++cows;
         }
      }

      if (bulls == answer_length) {
         cout << "Congratulations! You have found the answer...\n";
         return 0;
      }

      cout << bulls << " bull(s) and " << cows << " cow(s)\n";
      cout << "Guess again: ";
   }
}