/*
   Exercise 6 on Page 219

   Program that checks if a sentence is correct according to the following grammar:

   Sentence:
      Noun Verb " ."                      // note the space before the dot
      Sentence Conjuction Sentence " ."
   Conjunction:
      "and"
      "or"
      "but"
   Noun:
      Article Noun
      "birds"
      "fish"
      "C++"
   Article:
      "the"
   Verb:
      "rules"
      "fly"
      "swim"
*/

#include "../../std_lib_facilities.h"

const vector<string> nouns {"birds", "fish", "C++"};
const vector<string> verbs {"rules", "fly", "swim"};
const vector<string> conjunctions {"and", "or", "but"};

bool is_article(const string word)
{
   if (word == "the") {
      return true;
   }
   return false;
}

bool is_noun(string word)
{
   if (is_article(word)) {
      cin >> word;
   }

   for (string noun : nouns) {
      if (word == noun) {
         return true;
      }
   }
   return false;
}

bool is_verb(const string word)
{
   for (string verb : verbs) {
      if (word == verb) {
         return true;
      }
   }
   return false;
}

bool is_conjunction(const string word)
{
   for (string conjunction : conjunctions) {
      if (word == conjunction) {
         return true;
      }
   }
   return false;
}

bool sentence()
{
   string word;
   cin >> word;

   if (is_noun(word)) {
      cin >> word;

      if (is_verb(word)) {
         cin >> word;
         if (word == ".") {
            return true;
         }
         else if (is_conjunction(word)) {
            return sentence();
         }
      }
   }
   return false;
}

/// Prompts the user to enter if they wish to continue or not
/// If answer is yes returns true, otherwise return false
bool ask_user()
{
   // ignore anything remaining in cin
   cin.clear();
   cin.ignore(120, '\n');

   cout << "Try again ? [Y/n]: ";
   char input = 0;
   cin >> input;

   if (input == 'y' || input == 'Y') {
      return true;
   }
   return false;
}

int main()
try {
   bool keep_going = true;
   while (keep_going) {
      cout << "Please enter a sentence (ending with a ' .'): ";

      if (sentence()) {
         cout << "OK\n";
      }
      else {
         cout << "not OK\n";
      }
      keep_going = ask_user();
   }
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
