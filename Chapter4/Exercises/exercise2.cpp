/*
   Exercise 2 on Page 128

   Computes mean and median temperature
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<double> temperatures;

   cout << "Enter temperature values (enter any character to stop): ";
   for (double temp {}; cin >> temp; ) {
      temperatures.push_back(temp);
   }

   double sum {};
   for (double x : temperatures) {
      sum += x;
   }
   cout << "Average temperature: " << sum / temperatures.size() << '\n';

   sort(temperatures);

   double median {};

   if (temperatures.size() % 2 == 0) {
      median = (temperatures[(temperatures.size() / 2) - 1]
               + temperatures[(temperatures.size() / 2)]) / 2;
   }
   else {
      median = temperatures[temperatures.size() / 2];
   }
   cout << "Median temperature: " << median << '\n';
}
