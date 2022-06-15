/*
   Chapter 11 Exercise 13 Page 409
   Program that reverses the order of words in a file

   Usage: reverse_words <input_filename> <output_filename>
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

/// Splits a line into individual strings (including the " " spaces)
vector<string> split_line(const string& s)
{
   vector<string> split;

   if (s.length() != 0) {
      istringstream stream{s};
      for (string substring; stream >> substring;) {
         split.push_back(substring);

         // if not the last word
         if (stream.peek() != -1) {
            split.push_back(" ");
         }
      }
   }
   return split;
}

void write_vector_backwards(ostream& os, const vector<string>& vs)
{
   for (auto i = vs.rbegin(); i != vs.rend(); ++i) {
      os << *i;
   }
}

void write_words_reverse_order(istream& is, ostream& os)
{
   for (string line; getline(is, line);) {
      write_vector_backwards(os, split_line(line));
      os << '\n';
   }
}

int main(int argc, char const* argv[])
try {
   if (argc != 3) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: reverse_words <input_filename> <output_filename>";
      return 1;
   }

   ifstream in;
   open_file_input(argv[1], in);

   ofstream out;
   open_file_output(argv[2], out);

   write_words_reverse_order(in, out);
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