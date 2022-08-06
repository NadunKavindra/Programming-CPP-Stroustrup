/*
   Implements a Book Class
   Extended in Exercise 6 & 7
 */

#include "Book.h"
#include <iostream>

using std::cerr;
using std::cout;

int main()
try {
   Book test {"100-20-3-Y", "MAD-A", "Testing Book", 2022};
   cout << "ISBN: " << test.get_ISBN() << '\n' ;
   cout << "Author: " << test.get_author() << '\n';
   cout << "Title: " << test.get_title() << '\n';
   cout << "Copyright Year: " << test.get_copyright_year() << '\n';
   cout << "Checked Out: " << test.is_checked_out() << '\n';
   test.check_out();
   cout << "Checked Out: " << test.is_checked_out() << '\n';
   test.check_in();
   cout << "Checked Out: " << test.is_checked_out() << '\n';

   // Should throw an exception due to invalid ISBN
   Book test2 {"1000", "MAD-A", "Testing Book 2", 2022};
}
catch (const std::exception& exception) {
   cerr << "Error: " << exception.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception occurred\n";
   return 2;
}
