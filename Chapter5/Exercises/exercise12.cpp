/*
   Exercise 12 on Page 171

   A guessing game called "Bulls and Cows"
   The program has a vector of four different numbers in the range 0-9
   It is the user's task to discover these numbers by repeated guesses

   I found the solution of splitting a string to get the individual digits (as chars) simpler than using ints
   Also, using chars means that the program can be easily modified for guessing 4 letter words instead of numbers
   One downside of this approach is that the user can enter any 4 letter gibberish 
   and this would still be detected as a valid guess.
*/

#include "../../std_lib_facilities.h"

int main()
try {
   // would be better to fill the vector randomly but randomness not yet introduced in the book
   const vector<char> answer = {'1', '2', '3', '4'};
   const int answer_size = answer.size();
   
   string user_guess;

   cout << "Please make a guess (must be a " << answer_size << " digit number): ";
   while (cin >> user_guess) {
      int bulls = 0;
      int cows = 0;
      
      if (user_guess.length() > answer_size) {
         cout << "Input must have a length of " << answer_length << ". Please try again: ";
         continue;
      }

      for (int i = 0; i < answer_size; ++i) {
         if (user_guess[i] == answer[i])
            ++bulls;
         else if (find(answer.begin(), answer.end(), user_guess[i]) != answer.end()) 
            ++cows;
      }

      if (bulls == answer_size) {
         cout << "Congratulations! You have found the answer...\n";
         break;
      }

      cout << bulls << " bull(s) and " << cows << " cow(s)\n";
      cout << "Guess again: ";
   }
}
catch (exception& e) {
   cout << "Error: " << e.what();
}
catch (...) {
   cout << "Oops: unknown exception";
}
