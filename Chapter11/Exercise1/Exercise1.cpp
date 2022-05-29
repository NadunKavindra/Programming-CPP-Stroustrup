/*
   Chapter 11 Exercise 1 Page 408
   Program that read a text file and converts its input to all lower case, producing
   a new file
*/

#include <fstream>
#include <iostream>
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

void tolower(string& s)
{
   for (char& ch : s) {
      ch = static_cast<char>(tolower(ch));
   }
}

void write_lowercase(istream& in, ostream& out)
{
   for (string s; getline(in, s);) {
      tolower(s);
      out << s << '\n';
   }
}

int main(int argc, char const* argv[])
try {
   if (argc != 3) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: Exercise6 <input_filename> <output_filename> ";
      return 1;
   }

   ifstream in;
   open_file_input(argv[1], in);

   ofstream out;
   open_file_output(argv[2], out);

   write_lowercase(in, out);
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
