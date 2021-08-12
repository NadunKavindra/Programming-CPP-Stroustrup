/*
   Exercise 21 on Page 130

   Modified program from Exercise 19
   When you enter a integer, the program will output all the names with that score
   If there is no such score, outputs 'score not found'
*/

#include "../../std_lib_facilities.h"

vector<string> names;
vector<int> scores;

// checks if the provided name has been stored before
bool previously_entered(const string name)
{
   for (string s : names) {
      if (name == s) {
         return true;
      }
   }
   return false;
}

// Returns all the names with the provided score
vector<string> find_scores(int score)
{
   vector<string> results;

   for (int i { 0 }; i < scores.size(); ++i) {
      if (score == scores[i]) {
         results.push_back(names[i]);
      }
   }
   return results;
}

int main()
{
   string name;
   int score {};

   while (true) {
      cout << "Enter a name and a score (seperated by a space) or enter 'NoName  0' to stop: ";
      cin >> name >> score;

      if (!cin) {
         simple_error("invalid input value");
      }

      if (name == "NoName" && score == 0) {
         break;
      }

      // Per exercise description, program should terminate with an error message
      // when a name is entered twice
      if (previously_entered(name)) {
         simple_error("The name '" + name + "' has been entered before");
      }

      names.push_back(name);
      scores.push_back(score);
   }

   cout << "\nEnter the score which you wish to find (or enter a letter to exit): ";
   while (cin >> score) {
      const vector<string> results { find_scores(score) };

      if (results.empty()) {
         cout << "score not found\n";
      }
      else {
         cout << "\nThe names that have a score of " << score << ":\n";
         for (string s : results) {
            cout << s << '\n';
         }
      }
      cout << "\nEnter another score which you wish to find (or enter a letter to exit): ";
   }
}
