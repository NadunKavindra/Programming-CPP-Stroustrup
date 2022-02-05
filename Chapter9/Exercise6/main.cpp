#include <iostream>
#include "Book.hpp"

using namespace std;

int main()
try {
   Book test {"120-456-678-C", "M-Adaoglu", "Test Book", 2022};
   Book test2 {"120-567-432-5", "M-Adaoglu", "Test Book 2", 2022};
   cout << test << "\n\n";
   cout << test2 << "\n\n";

   cout << "test == test2 ? " << (test == test2) << '\n';
   cout << "test != test2 ? " << (test != test2) << '\n';

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
