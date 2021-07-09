/*
   Exercise 21 on Page 130

   Modified program from Exercise 19
   When you enter a integer, the program will output all the names with that score
   If there is no such score, outputs 'score not found'
*/

#include "../../std_lib_facilities.h"

vector<string> names;
vector<int> scores;


vector<string> find_names(int score)
{
   vector<string> results;

   for (int i = 0; i < scores.size(); ++i)
      if (score == scores[i])
         results.push_back(names[i]);

   return results;
}

int main()
{
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

   cout << "Enter the score which you wish to find: ";
   cin >> score;

   const vector<string> results = find_names(score);

   if (results.empty())
      cout << "score not found\n";
   else {
      cout << "The names that have a score of " << score << ":\n";
      for (string s : results)
         cout << s << '\n';
   }
}
