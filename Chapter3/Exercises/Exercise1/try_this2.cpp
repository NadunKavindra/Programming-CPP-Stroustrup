// A slightly modified version of the TRY THIS Exercise on Page 73
// Not exactly a useful program, just an exercise

#include "../../../std_lib_facilities.h"

int main()
{
   int number_of_words = 0;
   string previous = "";
   string current; 

   while (cin >> current) {
      ++number_of_words;
      
      if (previous == current)
         cout << "word number " << number_of_words;
         cout << " repeated word: " << current << '\n';
      
      previous = current;
   }
}
