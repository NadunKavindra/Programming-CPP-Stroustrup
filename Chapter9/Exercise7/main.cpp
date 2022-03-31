/*
   This exercise extends the Book class from Exercise 6:
      Implemented new enumerated type Genre
      Added data member genre to Book class
      Modified constructor and member functions appropriately
 */
#include "Book.h"
#include <iostream>

using std::cerr;
using std::cout;

int main()
try {
   Book test_book1 = {"100-20-3-Y", "MAD-A", "Testing Book", 2022, Genre::FICTION};
   cout << test_book1 << '\n';

   Book test_book2
       = {"100-20-45-3", "MAD-A", "Testing Book 2", 2022, Genre::BIOGRAPHY};

   cout << (test_book1 == test_book2) << '\n';
   cout << (test_book1 != test_book2) << '\n';
   cout << (test_book1 == test_book1) << '\n';
}
catch (const std::exception& exception) {
   cerr << "Error: " << exception.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception occurred\n";
   return 2;
}