/*
   Chapter 11 Exercise 3 Page 408

   Takes 2 command line arguments; input filename and output filename
   Removes all vowels ("disemvowels") from text read from the input file
   and writes the results to the output file
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>

using namespace std;

/// A wrapper around the ifstream constructor
/// @throws runtime_error if file cannot be opened
void open_file_input(const string& filename, ifstream& ifs)
{
   ifs = ifstream{filename};
   if (!ifs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

/// A wrapper around the ofstream constructor
/// @throws runtime_error if file cannot be opened/created
void open_file_output(const string& filename, ofstream& ofs)
{
   ofs = ofstream{filename};
   if (!ofs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

bool isvowel(char ch)
{
   const static string vowels = "aeiouy";

   ch = static_cast<char>(tolower(ch));

   for (const char vowel : vowels) {
      if (ch == vowel) {
         return true;
      }
   }
   return false;
}

void remove_vowels(string& s)
{
   s.erase(remove_if(s.begin(), s.end(), &isvowel), s.end());
}

void write_disemvoweled(istream& is, ostream& os)
{
   for (string s; getline(is, s);) {
      remove_vowels(s);
      os << s << '\n';
   }
}

int main(int argc, char const* argv[])
try {
   if (argc != 3) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: Exercise3 <input_filename> <output_filename>";
      return 1;
   }

   ifstream in;
   open_file_input(argv[1], in);

   ofstream out;
   open_file_output(argv[2], out);

   write_disemvoweled(in, out);
   return 0;
}
catch (const exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception\n";
   return 2;
}
