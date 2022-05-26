/*
   Chapter 10 Exercise 3 Page 377
   Calculates the mean and median temperature values in raw_temps.txt
 */
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

double mean(const std::vector<double>& v)
{
   double sum = 0;
   for (const double d : v) {
      sum += d;
   }
   return sum / v.size();
}

double median(std::vector<double> v)
{
   std::sort(v.begin(), v.end());
   size_t mid_index = v.size() / 2;

   if (v.size() % 2 == 0) {
      return (v[mid_index] + v[mid_index - 1]) / 2;
   }
   return v[mid_index];
}

int main()
try {
   std::ifstream ifs{"../raw_temps.txt"};

   if (!ifs) {
      std::cerr << "Could not open file for reading\n";
      return 1;
   }

   std::vector<double> temperatures;
   while (true) {
      // Data is stored as: hour temperature
      // we are only interested in temperature
      int hour;
      double temperature;

      if (!(ifs >> hour >> temperature)) {
         break;
      }
      temperatures.push_back(temperature);
   }

   std::cout << "Mean == " << mean(temperatures) << '\n';
   std::cout << "Median == " << median(temperatures) << '\n';
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
