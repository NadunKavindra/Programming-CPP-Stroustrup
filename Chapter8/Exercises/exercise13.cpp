/*
   Exercise 13 on Page 301
*/

#include "../../std_lib_facilities.h"

// Finds the shortest string inside a vector
string shortest_element(const vector<string>& v)
{
   if (v.empty()) {
      error("shortest_element --> cannot search empty vector");
   }
   string result {v[0]};

   for (int i {1}; i < v.size(); ++i) {
      if (v[i].length() < result.length()) {
         result = v[i];
      }
   }
   return result;
}

// Finds the longest string inside a vector
string longest_element(const vector<string>& v)
{
   if (v.empty()) {
      error("longerst_element --> cannot search empty vector");
   }
   string result {v[0]};

   for (int i {1}; i < v.size(); ++i) {
      if (v[i].length() > result.length()) {
         result = v[i];
      }
   }
   return result;
}

// Finds the lexicographically first string inside a vector
string lexicographically_first(const vector<string>& v)
{
   if (v.empty()) {
      error("lexicographically_first --> cannot search empty vector");
   }

   string first {v[0]};
   for (int i {0}; i < v.size(); ++i) {
      if (v[i] < first) {
         first = v[i];
      }
   }
   return first;
}

// Finds the lexicographically last string inside a vector
string lexicographically_last(const vector<string>& v)
{
   if (v.empty()) {
      error("lexicographically_last --> cannot search empty vector");
   }

   string last {v[0]};
   for (int i {0}; i < v.size(); ++i) {
      if (v[i] > last) {
         last = v[i];
      }
   }
   return last;
}

// Returns a vector containing the number of characters
// in each string present inside the provided vector
vector<int> number_of_chars(vector<string>& v)
{
   if (v.empty()) {
      error("number_of_chars --> cannot search empty vector");
   }

   vector<int> result;
   for (string s : v) {
      result.push_back(s.length());
   }

   return result;
}

// Prints a vector of ints to cout
// label used as a "heading" in the output
void print_i(const vector<int>& v, string label)
{
   cout << label << ": " << "{ ";

   for (int i {0}; i < v.size(); ++i) {
      cout << v[i];

      if (i != v.size() - 1) {
         cout << ", ";
      }
   }
   cout << " }" << '\n';
}

// Prints a vector of strings to cout
// label used as a "heading" in the output
void print_s(const vector<string>& v, string label)
{
   cout << label << ": " << "{ ";

   for (int i {0}; i < v.size(); ++i) {
      cout << v[i];

      if (i != v.size() - 1) {
         cout << ", ";
      }
   }
   cout << " }" << '\n';
}

int main()
try {
   vector<string> test_values {"hello", "do", "you", "like", "apples"};
   print_s(test_values, "TEST VALUES");

   print_i(number_of_chars(test_values), "NUMBER OF CHARACTERS");

   cout << "Shortest: " << shortest_element(test_values) << '\n';
   cout << "Longest: " << longest_element(test_values) << '\n';
   cout << "Lexicographically First: " << lexicographically_first(test_values) << '\n';
   cout << "Lexicographically Last: " << lexicographically_last(test_values) << '\n';
   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
