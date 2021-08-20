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

struct Name_value {
   string name;
   int score;
};

int main()
try {
   vector<Name_value> pairs;
   Name_value input;

   while (true) {
      cout << "Enter a name and a score (seperated by a space) or enter 'NoName  0' to stop: ";
      cin >> input.name >> input.score;

      if (!cin) {
         error("invalid input value");
      }

      if (input.name == "NoName" || input.name == "noname") {
         break;
      }

      // check previous entries
      for (Name_value p : pairs) {
         if (input.name == p.name) {
            // an error must be thrown per exercise description
            error(input.name, " has been entered before");
         }
      }

      pairs.push_back(input);
   }

   for (Name_value p: pairs) {
      cout << '(' << p.name << ", " << p.score << ")\n";
   }
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception\n";
   return 2;
}
