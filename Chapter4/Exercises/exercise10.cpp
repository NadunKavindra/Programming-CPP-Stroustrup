/*
   Exercise 10 on Page 129

   A simple game of "Rock, Paper and Scissors"

   Not truly random (randomness is yet to be introduced in the book)
*/

#include "../../std_lib_facilities.h"

int main()
{
   int player_wins = 0;
   int computer_wins = 0;
   int draw = 0;

   const vector<string> computer_moves = { "rock", "scissors", "paper", "paper", "rock" };

   string player_input = "";
   char player_move = 0;

   for (string computer_move : computer_moves) {
      cout << "rock, paper or scissors ? ";
      cin >> player_input;

      // convert user input to lowercase
      for (int i = 0; i < player_input.length(); ++i)
         player_input[i] = tolower(player_input[i]);

      if (player_input == "rock")
         player_move = 'r';
      else if (player_input == "paper")
         player_move = 'p';
      else if (player_input == "scissors")
         player_move = 's';
      else
         simple_error("invalid input");

      cout << "Player: " << player_input << '\n';
      cout << "Computer: " << computer_move << '\n';

      // Exercise description states that the program should use a switch
      switch (player_move) {
      case 'r':
         if (computer_move == "paper") {
            ++computer_wins;
            cout << "COMPUTER WINS!\n\n";
         }
         else if (computer_move == "scissors") {
            ++player_wins;
            cout << "PLAYER WINS\n\n";
         }
         else
            cout << "IT'S A DRAW!\n\n";

         break;

      case 's':
         if (computer_move == "rock") {
            ++computer_wins;
            cout << "COMPUTER WINS!\n\n";
         }
         else if (computer_move == "paper") {
            ++player_wins;
            cout << "PLAYER WINS\n\n";
         }
         else
            cout << "IT'S A DRAW!\n\n";

         break;

      case 'p':
         if (computer_move == "scissors") {
            ++computer_wins;
            cout << "COMPUTER WINS!\n\n";
         }
         else if (computer_move == "rock") {
            ++player_wins;
            cout << "PLAYER WINS\n\n";
         }
         else
            cout << "IT'S A DRAW!\n\n";

         break;
      }
   }

   if (player_wins > computer_wins)
      cout << "\n******** THE PLAYER HAS WON! ********\n\n";
   else if (computer_wins > player_wins)
      cout << "\n******** THE COMPUTER HAS WON! ********\n\n";
   else
      cout << "\n******** IT'S A TIE! NO ONE WINS! ********\n\n";
}
