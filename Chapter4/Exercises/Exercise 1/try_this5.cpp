/*
   TRY THIS Exercise on Page 116

   Square function without the use of the multiplication operator
*/

#include "../../../std_lib_facilities.h"

int square(int x) 
{
   int result = 0;

   for (int i = 0; i < x; ++i) {
      result += x;
   }

   return result;
}

int main()
{
   for (int i=0; i< 00; ++i) {
      cout << i << '\t' << square(i) << '\n';
   }
}
