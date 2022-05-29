/*
   Chapter 10 Exercise 9 Page 378
   Program that combines two files that contain alphabetical letters in sorted order.
   Preserves the alphabetical ordering after merge
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
/// @throws runtime_error if file cannot be opened/created
void open_file_output(const string& filename, ofstream& ofs)
{
   ofs = ofstream{filename};
   if (!ofs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

void merge_files_alphabetically(const string& input_filename_1,
                                const string& input_filename_2,
                                const string& output_filename)
{
   ifstream ifs_1;
   open_file_input(input_filename_1, ifs_1);

   ifstream ifs_2;
   open_file_input(input_filename_2, ifs_2);

   ofstream ofs;
   open_file_output(output_filename, ofs);

   string input_1;
   string input_2;
   ifs_1 >> input_1;
   ifs_2 >> input_2;

   while (ifs_1 || ifs_2) {
      if (input_1 <= input_2) {
         ofs << input_1 << '\n';
         if (!(ifs_1 >> input_1)) {
            // Can't read from ifs_1 anymore
            // set it to a character that is greater than English alphabetical characters
            input_1 = '~';
         }
      }
      else if (input_2 < input_1) {
         ofs << input_2 << '\n';
         if (!(ifs_2 >> input_2)) {
            // Can't read from ifs_2 anymore
            // set it to a character that is greater than English alphabetical characters
            input_2 = '~';
         }
      }
   }
}

int main(int argc, char const* argv[])
try {
   if (argc != 4) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: Exercise9 <input_filename> <input_filename> "
              "<output_filename>";
      return 1;
   }

   merge_files_alphabetically(string{argv[1]}, string{argv[2]}, string{argv[3]});
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
