/*
   Exercise 20 on Page 130

   Modified program from Exercise 19 
   When you enter a name, the program outputs the correspoding score
   If no such name exists, output 'no name found'
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<string> names;
   vector<int> scores;

   string name;
   int score;

   while (true) {
      cout << "Enter a name and a score (seperated by a space) or enter 'NoName  0' to stop: ";
      cin >> name >> score;

      if (name == "NoName" && score == 0)
         break;

      for (string s : names)
         if (name == s)
            simple_error("The name '" + name + "' has been entered before");

      names.push_back(name);
      scores.push_back(score);
   }

   cout << "\nEnter a name to find the correspoding score: ";
   cin >> name;

   bool name_found = false;

   for (int i = 0; i < names.size(); ++i) {
      if (name == names[i]) {
         name_found = true;
         score = scores[i];
         break;
      }
   }

   if (name_found)
      cout << name << " has a score of " << score << '\n';
   else
      cout << "name not found\n";
}
