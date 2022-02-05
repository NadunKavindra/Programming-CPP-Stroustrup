#include "Book.hpp"
#include <iostream>
#include <exception>

using namespace std;

int main()
try {
   Book test {"120-456-678-C", "M-Adaoglu", "Test Book", 2022};
   cout << test.get_isbn() << '\n';
   cout << test.get_author() << '\n';
   cout << test.get_title() << '\n';
   cout << test.get_copyright_year() << '\n';
   cout << test.is_checked_out() << '\n';
   test.checkout();
   cout << test.is_checked_out() << '\n';
   test.checkin();
   cout << test.is_checked_out() << '\n';

   Book test2 {"120", "M-Adaoglu", "Test Book", 2022};
   return 0;
}
catch (const exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
