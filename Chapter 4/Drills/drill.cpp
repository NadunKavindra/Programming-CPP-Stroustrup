/*
   Drill Exercise on Page 126

   As with most drill exercises, not exactly a useful program
   Proper error checking and handling is not explained until Chapter 5
   Hence, may not work properly with certain invalid inputs
*/

#include "../../std_lib_facilities.h"

void prompt_user()
{
   cout << "Enter a distance value followed by the unit (cm, m, in or ft)\n"
        << "Or '|' to exit: ";
}

bool check_unit(string unit)
{
   if (unit == "\n" || (unit != "cm" && unit != "m" && unit != "in" && unit != "ft"))
      return false;

   return true;
}

double convert_to_meters(double value, string unit)
{
   if (unit == "m")
      return value;
   else if (unit == "cm")
      return value / 100;
   else if (unit == "in")
      return value / 39.37;
   else
      return value / 3.281;  // convert to feet
}

int main()
{
   double value = 0;
   double sum = 0;  // sum of all values converted to meters
   int counter = 0;

   vector<double> numbers;

   string unit = "";

   prompt_user();
   cin >> value;
   getline(cin, unit);
   
   while (!check_unit(unit)) {
      cout << "Unknow unit! Try again.\n\n";
      prompt_user();
      cin >> value;
      getline(cin, unit);
   }

   value = convert_to_meters(value, unit);

   sum += value;
   numbers.push_back(value);
   ++counter;

   double largest = value;
   double smallest = value;

   prompt_user();
   while (cin >> value && getline(cin, unit)) {
      if (!check_unit(unit)) {
         cout << "Unknow unit! Try again.\n\n";
         continue;
      }

      value = convert_to_meters(value, unit);

      sum += value;
      numbers.push_back(value);
      ++counter;
      unit = "m";

      if (value > largest) {
         largest = value;
         cout << largest << unit << " the largest so far";
      }
      else if (value < smallest) {
         smallest = value;
         cout << smallest << unit << " the smallest so far";
      }
      cout << '\n';
      prompt_user();
   }

   cout << '\n' << "You entered " << counter << " values\n";

   sort(numbers);
   for (double num : numbers)
      cout << num << unit << ' ';

   cout << '\n' << "Smallest == " << smallest << unit << '\n';
   cout << "Largest == " << largest << unit << '\n';
   cout << "Sum == " << sum << unit << '\n';
}
