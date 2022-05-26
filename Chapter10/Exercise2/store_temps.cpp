/*
   Chapter 10 Exercise 2 Page 377
   Fills a .txt file with 50 Reading object data
 */

#include <fstream>
#include <iostream>
#include "Reading.h"


int main()
try {
   std::ofstream ofs{"../raw_temps.txt"};

   if (!ofs) {
      std::cerr << "Could not open/create file\n";
      return 1;
   }

   // Create 50 Reading objects and write them to the file
   for (int i = 0; i < 50; ++i) {
      ofs << Reading{i % 24, i + 20.0} << '\n';
   }
   return 0;
}
catch (const std::exception& e) {
   std::cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   std::cerr << "Oops: unknown exception\n";
   return 2;
}
