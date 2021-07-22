/*
   Exercise 2 on Page 128

   Computes mean and median temperature
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<double> temperatures;

   for (double temp; cin >> temp; )
      temperatures.push_back(temp);

   double sum = 0;
   for (double x : temperatures)
      sum += x;
   cout << "Average temperature: " << sum / temperatures.size() << '\n';

   sort(temperatures);

   double median = 0;

   if (temperatures.size() % 2 == 0) {
      median = (temperatures[(temperatures.size() / 2) - 1]
               + temperatures[(temperatures.size() / 2)]) / 2;
   }
   else
      median = temperatures[temperatures.size() / 2];

   cout << "Median temperature: " << median << '\n';
}
