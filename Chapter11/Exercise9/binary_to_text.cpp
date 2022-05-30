/*
   Chapter 11 Exercise 9 Part 2, Page 409
   Program that converts a "binary" file to text
   (Using the book's definition of "binary")
*/

// Need to use this for as_bytes() function
#include "../../std_lib_facilities.h"

/// A wrapper around the ifstream constructor
/// @throws runtime_error if file cannot be opened
void open_file_input(const string& filename, ifstream& ifs, bool binary = false)
{
   if (binary) {
      ifs = ifstream{filename, ios_base::binary};
   }
   else {
      ifs = ifstream{filename};
   }

   if (!ifs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

/// A wrapper around the ofstream constructor
/// @throws runtime_error if file cannot be opened/created
void open_file_output(const string& filename, ofstream& ofs, bool binary = false)
{
   if (binary) {
      ofs = ofstream{filename, ios_base::binary};
   }
   else {
      ofs = ofstream{filename};
   }

   if (!ofs) {
      throw runtime_error("Cannot open file " + filename);
   }
}

string change_file_extension(const string& filename, const string& new_extension)
{
   return filename.substr(0, filename.find_last_of('.') + 1) + new_extension;
}

int main(int argc, char const* argv[])
try {
   if (argc != 2) {
      cerr << "Incorrect usage.\n"
           << "Correct Usage: binary_to_text <input_filename>";
      return 1;
   }

   ifstream in;
   open_file_input(argv[1], in, true);

   const string output_filename = change_file_extension(argv[1], "txt");
   ofstream out;
   open_file_output(output_filename, out);

   for (char ch; in.read(as_bytes(ch), sizeof(char));) {
      out << ch;
   }

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