#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   ifstream ifs{"ints.txt"};

   if (!ifs) {
      cerr << "Couldn't open the file\n";
      return 1;
   }

   int sum = 0;
   for (int i = 0; ifs >> i; sum += i)
      ;

   cout << "Sum: " << sum << '\n';  // Should be 100
   return 0;
}
