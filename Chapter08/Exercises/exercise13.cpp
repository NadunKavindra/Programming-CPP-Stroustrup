/*
   Exercise 13 on Page 301
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/// @returns the shortest string inside a vector
string shortest_element(const vector<string>& v)
{
   if (v.empty()) {
      invalid_argument("shortest_element --> cannot search empty vector");
   }

   string result = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i].length() < result.length()) {
         result = v[i];
      }
   }
   return result;
}

/// @returns the longest string inside a vector
string longest_element(const vector<string>& v)
{
   if (v.empty()) {
      invalid_argument("longerst_element --> cannot search empty vector");
   }

   string result = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i].length() > result.length()) {
         result = v[i];
      }
   }
   return result;
}

/// @returns the lexicographically first string inside a vector
string lexicographically_first(const vector<string>& v)
{
   if (v.empty()) {
      invalid_argument("lexicographically_first --> cannot search empty vector");
   }

   string first = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] < first) {
         first = v[i];
      }
   }
   return first;
}

/// @returns the lexicographically last string inside a vector
string lexicographically_last(const vector<string>& v)
{
   if (v.empty()) {
      invalid_argument("lexicographically_last --> cannot search empty vector");
   }

   string last = v[0];
   for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] > last) {
         last = v[i];
      }
   }
   return last;
}

/// @returns a vector containing the number of characters
/// in each string present inside the provided vector
vector<int> number_of_chars(const vector<string>& v)
{
   if (v.empty()) {
      invalid_argument("number_of_chars --> cannot search empty vector");
   }

   vector<int> result;
   for (string s : v) {
      result.push_back(s.length());
   }

   return result;
}

/// Prints a vector of ints to cout
/// @param label used as a "heading" in the output
void printv_int(const vector<int>& v, const string& label)
{
   cout << label << " == " << "{ ";

   for (size_t i = 0; i < v.size(); ++i) {
      cout << v[i];

      if (i != v.size() - 1) {
         cout << ", ";
      }
   }
   cout << " }" << '\n';
}

/// Prints a vector of string to cout
/// @param label used as a "heading" in the output
void printv_string(const vector<string>& v, const string& label)
{
   cout << label << " == " << "{ ";

   for (size_t i = 0; i < v.size(); ++i) {
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
   printv_string(test_values, "TEST VALUES");

   printv_int(number_of_chars(test_values), "NUMBER OF CHARACTERS");

   cout << "Shortest: " << shortest_element(test_values) << '\n';
   cout << "Longest: " << longest_element(test_values) << '\n';
   cout << "Lexicographically First: " << lexicographically_first(test_values)
        << '\n';
   cout << "Lexicographically Last: " << lexicographically_last(test_values) << '\n';
   return 0;
}
catch (const exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception\n";
   return 2;
}
