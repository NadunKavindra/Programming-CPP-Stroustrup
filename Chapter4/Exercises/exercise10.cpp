/*
   Exercise 10 on Page 129

   A simple game of "Rock, Paper and Scissors"

   Computer moves are not random (randomness is yet to be introduced in the book)
*/

#include "../../std_lib_facilities.h"

constexpr char rock { 'r' };
constexpr char paper { 'p' };
constexpr char scissors { 's' };
const vector<string> computer_moves { "rock", "scissors", "paper", "paper", "rock" };

int player_wins {};
int computer_wins {};
int draws {};

// returns lowercase version of the provided string
string tolower_string(string s)
{
   string lower_s;

   for (char c : s) {
      lower_s += tolower(c);
   }

   return lower_s;
}

// Used to validate input and return appopriate char designation for player_move
// Exercise description states that the program should use a switch (which does not work with strings)
char get_player_move(string input)
{
   if (input == "rock" || input == "r") {
      return rock;
   }
   else if (input == "paper" || input == "p") {
      return paper;
   }
   else if (input == "scissors" || input == "s") {
      return scissors;
   }
   else {
      simple_error("invalid input");
   }
}

void play(string input, string computer_move)
{
   input = tolower_string(input);
   char player_move { get_player_move(input) };

   cout << "Player: " << input << '\n';
   cout << "Computer: " << computer_move << '\n';

   // Exercise description states that the program should use a switch
   // TBH not the most elegant approach
   switch (player_move) {
   case rock:
      if (computer_move == "paper") {
         ++computer_wins;
         cout << "COMPUTER HAS WON!\n\n";
      }
      else if (computer_move == "scissors") {
         ++player_wins;
         cout << "PLAYER HAS WON\n\n";
      }
      else {
         ++draws;
         cout << "IT'S A DRAW!\n\n";
      }
      break;
   case scissors:
      if (computer_move == "rock") {
      ++computer_wins;
      cout << "COMPUTER HAS WON!\n\n";
      }
      else if (computer_move == "paper") {
         ++player_wins;
         cout << "PLAYER HAS WON\n\n";
      }
      else {
         ++draws;
         cout << "IT'S A DRAW!\n\n";
      }
      break;
   case paper:
      if (computer_move == "scissors") {
         ++computer_wins;
         cout << "COMPUTER HAS WON!\n\n";
      }
      else if (computer_move == "rock") {
         ++player_wins;
         cout << "PLAYER HAS WON\n\n";
      }
      else {
         ++draws;
         cout << "IT'S A DRAW!\n\n";
      }
      break;
   }
}

void print_scoreboard()
{
   cout << "Player wins: " << player_wins << '\n';
   cout << "Computer wins: " << computer_wins << '\n';
   cout << "Draws: " << draws << "\n\n";
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

int main()
{
   string input;

   for (string computer_move : computer_moves) {
      cout << "rock, paper or scissors ? ";
      cin >> input;
      cout << '\n';

      play(input, computer_move);
      print_scoreboard();
   }

   print_game_results();
   keep_window_open();  // to cope with Win32 console shutdown
}
