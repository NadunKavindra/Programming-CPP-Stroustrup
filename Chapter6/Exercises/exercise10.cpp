#include "../../std_lib_facilities.h"

/// Returns n!
int factorial(const int n)
{
   if (n < 0) {
      error("can't perform factorial operation on a negative number");
   }

   int result = 1;

   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}

/// Returns result of P(a, b)
int permutation(int const a,int const b)
{
   if (b > a) {
      error("The value of b cannot be greater than a");
   }
   return factorial(a) / factorial(a-b);
}

/// Returns result of C(a,b)
int combination(int a, int b)
{
   return permutation(a, b) / factorial(b);
}

void run_exercise()
{
   char user_input;
   cout << "Calculate a permutation or combination ? [p/c]: ";
   cin >> user_input;
   user_input = static_cast<char>(toupper(user_input));

   if (user_input != 'C' && user_input != 'P') {
      cout << '\n';
      error("invalid input value");
   }

   int a;
   int b;

   cout << user_input << "(a,b)\n";
   cout << "Enter value of a: ";
   cin >> a;
   cout << "Enter value of b: ";
   cin >> b;

   switch (user_input) {
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
   run_exercise();
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
