#include "../../std_lib_facilities.h"

class Patron {
public:
   Patron(string name, unsigned card_number) : name {name}, card_number {card_number} {}

   Patron(string name, unsigned card_number, double fee_owed);
   void set_fee_owed(double fee);

   string get_name() const { return name; }
   unsigned get_card_number() const { return card_number; }
   double get_fee_owed() const { return fee_owed; }
private:
   string name;
   unsigned card_number;
   double fee_owed {0};
};

Patron::Patron(string name, unsigned card_number, double fee_owed)
   : name {name}, card_number {card_number}, fee_owed {fee_owed}
{
   if (fee_owed < 0) {
      error("fee_owed must be a non-negative number but is ", fee_owed);
   }
}

void Patron::set_fee_owed(double fee)
{
   if (fee < 0) {
      error("fee must be a non-negative number but is ", fee);
   }
   fee_owed = fee;
}

// not really needed but is specified in the exercise description
bool owes_fee(const Patron& p)
{
   return p.get_fee_owed();
}

int main()
try {
   Patron test {"Mustafa", 1234, 300};

   if (owes_fee(test)) {
      cout << test.get_name() << " owes " << test.get_fee_owed() << "$\n";
   };
}
catch (exception& e) {
   cerr << "Error: " << e.what() << '\n';
}
catch (...) {
   cerr << "Error: unknown exception\n";
}
