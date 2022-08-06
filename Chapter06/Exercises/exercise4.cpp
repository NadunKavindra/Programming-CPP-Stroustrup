/*
   Exercise 4 on Page 218

   Essentialy a rework of exercise 19 on page 130

   While the exercise asks Name_value to be created as a class,
   I think making it a struct makes more sense

   Program where you first enter a set of name-value pairs, such as Joe 17
   Checks that each name is unique, throws an error if name entered twice
   Terminates input operation when 'NoName 0' is entered
*/

#include "../../std_lib_facilities.h"

struct NameValuePair {
   string name;
   int score;
};

void run_exercise()
{
   vector<NameValuePair> pairs;
   NameValuePair input;

   while (true) {
      cout << "Enter a name and a score (seperated by a space)"
           << "or enter 'NoName  0' to stop: ";

      if (!(cin >> input.name >> input.score)) {
         error("invalid input value");
      }

      if (input.name == "NoName" || input.name == "noname") {
         break;
      }

      // check previous entries
      for (NameValuePair p : pairs) {
         if (input.name == p.name) {
            // an error must be thrown per exercise description
            error(input.name, " has been entered before");
         }
      }
      pairs.push_back(input);
   }
   for (NameValuePair p : pairs) {
      cout << '(' << p.name << ", " << p.score << ")\n";
   }
}

int main()
try {
   run_exercise();
   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception\n";
   return 2;
}
