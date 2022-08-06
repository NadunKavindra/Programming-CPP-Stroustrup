#include "NamePairs.h"
#include <iostream>

int main()
try {
   NamePairs test;

   test.read_names();
   std::cout << '\n';

   test.read_ages();
   std::cout << '\n';

   std::cout << '\n'  << "Unsorted" << '\n';
   test.print();
   std::cout << '\n';

   std::cout << '\n' <<"Sorted" << '\n';
   test.sort();
   test.print();
   std::cout << '\n';

   return 0;
}
catch (const std::exception& exception) {
   std::cerr << "Error: " << exception.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Error: unknown exception\n";
   return 2;
}
