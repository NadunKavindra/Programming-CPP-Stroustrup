/*
   Exercise 2 on Page 128

   Computes mean and median temperature
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<double> temperatures;

   cout << "Enter temperature values (enter any character to stop): ";
   for (double temp = 0; cin >> temp; ) {
      temperatures.push_back(temp);
   }

   double sum = 0;
   for (double x : temperatures) {
      sum += x;
   }
   cout << "Average temperature: " << sum / temperatures.size() << '\n';

   // Temperatures need to be sorted before computing median
   sort(temperatures);

   double median = 0;
   size_t mid_index = temperatures.size() / 2;

   if (temperatures.size() % 2 == 0) {
      median = (temperatures[mid_index] + temperatures[mid_index - 1]) / 2;
   }
   else {
      median = temperatures[mid_index];
   }
   cout << "Median temperature: " << median << '\n';
}
