/*
   TRY THIS Exercise on Page 109
*/

#include "../../../std_lib_facilities.h"

int main()
{
   constexpr double yen_to_usd = 0.0090;
   constexpr double kroner_to_usd = 0.12;
   constexpr double pounds_to_usd = 1.39;
   constexpr double yuan_to_usd = 0.15;

   double amount = 0;
   char currency = 0;

   cout << "Please enter amount followed by a currency ('y' (Yen), 'k' (Kroner), 'p' (Pounds) or 'c' (Yuan)):\n";
   cin >> amount >> currency;

   switch (currency) {
      case 'y':
         cout << amount << " yen == " << amount * yen_to_usd << " dollars\n";
         break;
      case 'k':
         cout << amount << " kroner == " << amount * kroner_to_usd << " dollars\n";
         break;
      case 'p':
         cout << amount << " pounds == " << amount * pounds_to_usd << " dollars\n";
         break;
      case 'c':
         cout << amount << " yuan == " << amount * yuan_to_usd << " dollars\n";
         break;
      default:
         cout << "Sorry, I don't know a currency called '" << currency <<"'\n";  
   }
}
