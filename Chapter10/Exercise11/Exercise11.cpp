/*
   Chapter 10 Exercise 11 Page 378
   Program that produces the sum of all integers in a file
*/

#include <string>
#include <fstream>
#include <iostream>

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

/// Skips to the next integet in the filestream
void skip_to_int(istream& is)
{
   if (is.fail()) {
      is.clear();

      for (char ch; is >> ch; ) {
         if (isdigit(ch) || ch == '-') {
            is.unget();
            return;
         }
      }
   }
}

int sum_of_integers(ifstream& ifs)
{
   int sum = 0;
   while (ifs) {
      for (int n = 0; ifs >> n; sum += n);
      skip_to_int(ifs);
   }
   return sum;
}

int main()
try {
   ifstream ifs;
   open_file_input("test.txt", ifs);

   int sum = sum_of_integers(ifs);

   cout << "The sum of all the integers in the file: " << sum << '\n';
}
catch (const std::exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Oops: unknown exception\n";
   return 2;
}
