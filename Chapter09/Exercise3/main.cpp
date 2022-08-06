#include "NamePairs.h"
#include <iostream>

int main()
try {
   NamePairs test1;

   test1.read_names();
   test1.read_ages();

   std::cout << '\n'  << "Unsorted" << '\n';
   std::cout << test1;
   std::cout << '\n';

   std::cout << '\n' <<"Sorted" << '\n';
   test1.sort();
   std::cout << test1;
   std::cout << '\n';

   NamePairs test2;
   test2.read_names();
   test2.read_ages();
   std::cout << '\n';

   std::cout << (test1 == test2) << '\n';
   std::cout << (test1 != test2) << '\n';
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
