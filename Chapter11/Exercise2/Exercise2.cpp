/*
   Chapter 11 Exercise 2 Page 408
   Given a file name and a word (as command line arguments)
   Outputs each line that contains that word together with the line number

   NOTE: The search for the keyword could be improved but,
         for an exercise I think it's sufficient
*/

#include <fstream>
#include <iostream>
#include <sstream>
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

/// Returns true if the target string contains the keyword (case sensitive)
/// @param target the string to be searched
/// @param keyword the string to be searched for
bool contains(const string& keyword, const string& target)
{
   istringstream is{target};
   for (string s; is >> s;) {
      if (target.find(keyword) != target.npos) {
         return true;
      }
   }
   return false;
}

void find_word(istream& is, const string& word)
{
   string s;
   for (int line_number = 1; getline(is, s); ++line_number) {
      if (contains(word, s)) {
         cout << line_number << '\t' << s << '\n';
      }
   }
}

int main(int argc, char const* argv[])
try {
   if (argc != 3) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: Exercise2 <input_filename> <word> ";
      return 1;
   }

   ifstream in;
   open_file_input(argv[1], in);

   find_word(in, argv[2]);

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
