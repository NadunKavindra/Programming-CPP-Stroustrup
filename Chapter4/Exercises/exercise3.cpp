/*
   Exercise 3 on Page 128
*/

#include "../../std_lib_facilities.h"

int main()
{
   vector<double> distances;

   double min = 10000000000000000000;
   double max = 0;
   double sum = 0;

   cout << "Please enter a sequence of floating-point values (distances) seperated by a space\n";
   cout << "Or, enter a non-positive value to stop\n";

   double val;
   while (cin >> val && val > 0) {
      distances.push_back(val);
      sum += val;

      if (val < min) {
         min = val;
      }

      if (val > max) {
         max = val;
      }
   }


   cout << '\n' << "The total distance: " << sum << '\n';
   cout << "The smallest distance between two neighbouring cities: " << min << '\n';
   cout << "The greatest distance between two neighbouring cities: " << max << '\n';
   cout << "The mean distance between two neighbouring cities: " << sum / distances.size() << '\n';
}
