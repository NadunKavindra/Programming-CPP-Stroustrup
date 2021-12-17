/*
   Exercise 10 on Page 129

   A simple game of "Rock, Paper and Scissors"

   Computer moves are not random (randomness is yet to be introduced in the
   book)
*/

#include "../../std_lib_facilities.h"


int player_wins = 0;
int computer_wins = 0;
int draw = 0;

void evaluate_round(char player_move, const char computer_move)
{
   constexpr char rock = 'r';
   constexpr char paper = 'p';
   constexpr char scissors = 's';

   player_move = static_cast<char>(tolower(player_move));

   if (player_move == computer_move) {
      ++draw;
      return;
   }

   // Exercise specifies that a switch should be used
   switch (player_move) {
   case rock:
      if (computer_move == paper) {
         ++computer_wins;
      }
      else if (computer_move == scissors) {
         ++player_wins;
      }
      break;
   case paper:
      if (computer_move == scissors) {
         ++computer_wins;
      }
      else if (computer_move == rock) {
         ++player_wins;
      }
      break;
   case scissors:
      if (computer_move == rock) {
         ++computer_wins;
      }
      else if (computer_move == paper) {
         ++player_wins;
      }
      break;
   default:
      simple_error("Invalid player move");
   }
}

void print_scoreboard()
{
   cout << "Player wins: " << player_wins << '\n';
   cout << "Computer wins: " << computer_wins << '\n';
   cout << "Draws: " << draw << "\n\n";
}

void print_game_results()
{
   if (player_wins > computer_wins) {
      cout << "******** THE PLAYER HAS WON THE GAME! ********\n";
   }
   else if (computer_wins > player_wins) {
      cout << "******** THE COMPUTER HAS WON THE GAME! ********\n";
   }
   else {
      cout << "******** IT'S A TIE! NO ONE WINS! ********\n";
   }
}

void play()
{
   const vector<string> computer_moves {"rock", "scissors", "paper", "paper", "rock"};

   for (string computer_move : computer_moves) {
      cout << "rock, paper or scissors ? ";

      string player_move;
      cin >> player_move;

      cout << "\nPlayer: " << player_move << '\n';
      cout << "Computer: " << computer_move << '\n';

      evaluate_round(player_move[0], computer_move[0]);

      cout << '\n';
      print_scoreboard();
   }
   print_game_results();
}

int main() { play(); }
