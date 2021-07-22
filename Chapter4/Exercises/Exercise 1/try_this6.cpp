/*
   TRY THIS Exercise on Page 125
*/

#include "../../../std_lib_facilities.h"

int main()
{
   vector<string> words;
   const string disliked = "broccoli";
   
   for (string input; cin >> input; ) 
      words.push_back(input);

   for (string word: words) {
      if (word == disliked) 
         cout << "BLEEP\n";
      else 
         cout << word << '\n';
   }
}
