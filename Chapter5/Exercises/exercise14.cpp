/*
   Exercise 14 on Page 171

   Reads (day-of-the-week, number) pairs from standard input.
   Writes out the values entered and the sum for each day of the week
*/

#include "../../std_lib_facilities.h"

// Returns all lowercase version of s
string tolower_string(string s)
{
   for (int i { 0 }; i < s.size(); ++i) {
      s[i] = tolower(s[i]);
   }
   return s;
}

// Returns the sum of the values of vector v
int sum_of_vector(const vector<int> v)
{
   int sum { 0 };

   for (int value : v) {
      sum += value;
   }
   return sum;
}

// Prints out the values of vector v
void print_vector(const vector<int> v)
{
   if (v.empty()) {
      cout << "NO VALUES";
      return;
   }

   for (int value : v) {
      cout << value << ' ';
   }
}

int main()
{
   vector<int> monday;
   vector<int> tuesday;
   vector<int> wednesday;
   vector<int> thursday;
   vector<int> friday;
   vector<int> saturday;
   vector<int> sunday;

   int reject_counter { 0 };

   int value {};
   string day;

   cout << "Enter day-of-the-week value pairs, ex. Tuesday 23 (Enter 'done 0' to stop)):\n";
   while (true) {
      cin >> day >> value;

      if (!cin) {
         ++reject_counter;
         cout << "Rejected: Invalid value\n\n";
         cin.clear();
	      cin.ignore(120, '\n');
         continue;
      }

      day = tolower_string(day);

      if (day == "done") {
         break;
      }

      // Would be simpler with a switch statement
      // but C++ does not support switch on strings
      if (day == "monday" || day == "mon") {
         monday.push_back(value);
      }
      else if (day == "tuesday" || day == "tue" || day == "tues") {
         tuesday.push_back(value);
      }
      else if (day == "wednesday" || day == "wed") {
         wednesday.push_back(value);
      }
      else if (day == "thursday" || day == "thu" || day == "thur" || day == "thurs") {
         thursday.push_back(value);
      }
      else if (day == "friday" || day == "fri") {
         friday.push_back(value);
      }
      else if (day == "saturday" || day == "sat") {
         saturday.push_back(value);
      }
      else if (day == "sunday" || day == "sun") {
         sunday.push_back(value);
      }
      else {
         cout << "Rejected: invalid day\n\n";
         ++reject_counter;
      }
   }

   cout << "\nRejected " << reject_counter << " value(s)\n\n";

   cout << "Monday == ";
   print_vector(monday);
   cout << '\n';
   cout << "Sum of values for Monday == " << sum_of_vector(monday) << "\n\n";

   cout << "Tuesday == ";
   print_vector(tuesday);
   cout << '\n';
   cout << "Sum of values for Tuesday == " << sum_of_vector(tuesday) << "\n\n";

   cout << "Wednesday == ";
   print_vector(wednesday);
   cout << '\n';
   cout << "Sum of values for Wednesday == " << sum_of_vector(wednesday) << "\n\n";

   cout << "Thursday == ";
   print_vector(thursday);
   cout << '\n';
   cout << "Sum of values for Thursday == " << sum_of_vector(thursday) << "\n\n";

   cout << "Friday == ";
   print_vector(friday);
   cout << '\n';
   cout << "Sum of values for Friday == " << sum_of_vector(friday) << "\n\n";

   cout << "Saturday == ";
   print_vector(saturday);
   cout << '\n';
   cout << "Sum of values for Saturday == " << sum_of_vector(saturday) << "\n\n";

   cout << "Sunday == ";
   print_vector(sunday);
   cout << '\n';
   cout << "Sum of values for Sunday == " << sum_of_vector(sunday) << "\n\n";
}
