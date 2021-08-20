#include "../../std_lib_facilities.h"

// returns n!
long long factorial(long long n)
{
   if (n < 0) {
      error("can't perform factorial operation on a negative number");
   }

   long long result { 1 };

   for (long long i {2}; i <= n; ++i) {
      result *= i;
   }

   return result;
}

// returns result of P(a, b)
long long permutation(long long a, long long b)
{
   if (b > a) {
      error("The value of b cannot be greater than a");
   }

   return factorial(a) / factorial(a-b);
}

// returns result of C(a,b)
long long combination(long long a, long long b)
{
   return permutation(a, b) / factorial(b);
}

string tolower_string(string s) {
   string lower_s {};

   for (char c: s) {
      lower_s += tolower(c);
   }

   return lower_s;
}

// prompt user to make a choice between permutation or combination
char ask_user()
{
   cout << "Calculate a permutation or combination ? [p/c]: ";
   string choice;
   cin >> choice;
   choice = tolower_string(choice);

   if (choice == "permutation" || choice == "p") {
      return 'P';
   }
   else if (choice == "combination" || choice == "c") {
      return 'C';
   }
   else {
      error("invalid choice");
   }
}

void calculate()
{
   const char user_choice { ask_user() };

   long long a {};
   long long b {};

   cout << user_choice << "(a,b)\n";
   cout << "Enter value of a: ";
   cin >> a;
   cout << "Enter value of b: ";
   cin >> b;

   if (!cin) {
      cout << '\n';
      error("invalid input value");
   }

   switch (user_choice) {
   case 'P':
      cout  << "= " << permutation(a, b) << '\n';
      break;
   case 'C':
      cout << "= " << combination(a, b) << '\n';
      break;
   }
}

int main()
try {
   calculate();
   return 0;
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception" << '\n';
   return 2;
}
