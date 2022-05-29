/*
   Chapter 10 Exercise 8 Page 378
   Program that concatenates two files
*/

#include <fstream>
#include <iostream>
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
/// @throws invalid_argument if file cannot be opened/created
void open_file_output(const string& filename, ofstream& ofs)
{
   ofs = ofstream{filename};
   if (!ofs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

void write_entire_file_contents(ifstream& ifs, ofstream& os)
{
   for (string s; getline(ifs, s); os << s << '\n');
}

int main(int argc, char const* argv[])
try {
   if (argc != 4) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: Exercise8 <input_filename> <input_filename> "
              "<output_filename>";
      return 1;
   }

   ifstream input_filestream;
   open_file_input(string{argv[1]}, input_filestream);

   ifstream input_filestream2;
   open_file_input(string{argv[2]}, input_filestream2);

   ofstream output_filestream;
   open_file_output(string{argv[3]}, output_filestream);

   write_entire_file_contents(input_filestream, output_filestream);
   write_entire_file_contents(input_filestream2, output_filestream);

   return 0;
}
catch (const std::exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception\n";
   return 2;
}
