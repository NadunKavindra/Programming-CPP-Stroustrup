/*
   Exercise 20 on Page 130

   Modified program from Exercise 19
   When you enter a name, the program outputs the correspoding score
   If no such name exists, output 'no name found'
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

// Finds and displays the corresponding score of the provided name
void find_name(const string name)
{
   bool name_found { false };
   int score {};

      for (int i { 0 }; i < names.size(); ++i) {
         if (name == names[i]) {
            name_found = true;
            score = scores[i];
            break;
         }
      }

      if (name_found) {
         cout << name << " has a score of " << score << '\n';
      }
      else {
         cout << "name not found\n";
      }
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

      // exercise description states that program should terminate with an error message
      // if a name is entered twice
      if (previously_entered(name)) {
         simple_error("The name '" + name + "' has been entered before");
      }

      names.push_back(name);
      scores.push_back(score);
   }

   while (true) {
      cout << "\nEnter a name to find the correspoding score (enter '|' to exit): ";
      cin >> name;

      if (name == "|") {
         break;
      }

      find_name(name);
   }
}
