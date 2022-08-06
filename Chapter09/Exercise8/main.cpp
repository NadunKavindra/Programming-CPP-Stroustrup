/*
      Chapter 9 Exercise 8 on Page 340
      Implements a Patron class for a library
 */

#include "Patron.h"
#include <iostream>

using std::cerr;
using std::cout;

int main()
try {
   Patron test_patron = {"John Doe", 1};
   cout << "Name: " << test_patron.get_name() << '\n';
   cout << "Library Card Number: " << test_patron.get_card_number() << "\n\n";
   cout << "Fees Owed: " << test_patron.get_fees_owed() << '\n';
   cout << "Owes fees? " << owes_fees(test_patron) << '\n';

   test_patron.add_fee(245);
   cout << "Fees Owed: " << test_patron.get_fees_owed() << '\n';
   cout << "Owes fees? " << owes_fees(test_patron) << '\n';

   test_patron.reduce_fee_owed(245);
   cout << "Fees Owed: " << test_patron.get_fees_owed() << '\n';
   cout << "Owes fees? " << owes_fees(test_patron) << '\n';

   test_patron.reduce_fee_owed(10); // Should throw an exception
   return 0;
}
catch (const std::exception& exception) {
   cerr << "Error: " << exception.what() << '\n';
   return 1;
}
catch (...) {
   cerr << "Error: unknown exception occurred\n";
   return 2;
}
