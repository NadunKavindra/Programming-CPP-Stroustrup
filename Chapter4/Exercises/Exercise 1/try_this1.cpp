/*
   TRY THIS Exercise on Page 105
*/

#include "../../../std_lib_facilities.h"

int main()
{
   constexpr double yen_to_usd = 0.0090;
   constexpr double kroner_to_usd = 0.12;
   constexpr double pounds_to_usd = 1.39;

   double amount = 0;
   char currency = 0;

   cout << "Please enter amount followed by a currency ('y' (Yen), 'k' (Kroner), 'p' (Pounds) or 'c' (Yuan)):\n";
   cin >> amount >> currency;

   if (currency == 'y')
      cout << amount << " yen == " << amount * yen_to_usd << " dollars\n";
   else if (currency == 'k') 
      cout << amount << " kroner == " << amount * kroner_to_usd << " dollars\n";
   else if (currency == 'p')
      cout << amount << " pounds == " << amount * pounds_to_usd << " dollars\n";
   else 
      cout << "Sorry, I don't know a currency called '" << currency <<"'\n";  
}
