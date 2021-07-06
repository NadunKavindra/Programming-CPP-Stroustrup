/*
   TRY THIS Exercise on Page 111
*/

#include "../../../std_lib_facilities.h"

int main()
{
   char c = 'a';

   while (c <= 'z') {
      cout << c << '\t' << int{c} << '\n';
      ++c;
   }
}
