/*
   Exercise 19 on Page 130

   Program where you first enter a set of name-value pairs, such as Joe 17
   Checks that each name is unique, terminates with an error if name entered twice
   Terminates input operation when 'NoName 0' is entered
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<string> names;
   vector<int> scores;

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

      // check previous entries
      for (string s : names) {
         if (name == s) {
            simple_error("The name '" + name + "' has been entered before");
         }
      }

      names.push_back(name);
      scores.push_back(score);
   }

   for (int i { 0 }; i < names.size(); ++i) {
      cout << '(' << names[i] << ", " << scores[i] << ")\n";
   }
}
