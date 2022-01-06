/*
   Exercise 20 on Page 130

   Modified program from Exercise 19
   When you enter a name, the program outputs the correspoding score
   If no such name exists, output 'no name found'
*/

#include "../../std_lib_facilities.h"

vector<string> names;
vector<int> scores;

/// Returns the position in the names vector
/// Returns -1 if the provided string is not in the vector
int find_name(const string name)
{
   for (size_t i = 0; i < names.size(); ++i) {
      if (name == names[i]) {
         return i;
      }
   }
   return -1;
}

int main()
{
   string name;
   int score = 0;

   while (true) {
      cout << "Enter a name and a score (seperated by a space) or enter 'NoName  0' "
              "to stop: ";
      cin >> name >> score;

      if (!cin) {
         simple_error("invalid input value");
      }

      if (name == "NoName" && score == 0) {
         break;
      }

      // exercise description states that program should terminate with an error
      // message if a name is entered twice
      if (find_name(name) != -1) {
         simple_error("The name '" + name + "' has been entered before");
      }

      names.push_back(name);
      scores.push_back(score);
   }

   while (true) {
      cout << "\nEnter a name to find the correspoding score"
           << "(enter just '|' to exit): ";
      cin >> name;

      if (name[0] == '|') {
         break;
      }

      const int index = find_name(name);

      if (index == -1) {
         cout << "Name not found!\n";
      }
      else {
         cout << name << " has a score of: " << scores[index] << '\n';
      }
   }
}
