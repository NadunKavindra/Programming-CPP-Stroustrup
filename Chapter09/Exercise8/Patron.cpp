#include "Patron.h"
#include <stdexcept>
#include <string>

Patron::Patron(const std::string& name, const int card_number, const int fees)
    : name{name}, card_number{card_number}, fees_owed{fees}
{
   if (fees_owed < 0) {
      throw std::invalid_argument("The fees owed must be a positive number");
   }
}

Patron::Patron(const std::string& name, const int card_number)
    : name{name}, card_number{card_number}
{
}

void Patron::add_fee(const int amount)
{
   if (amount <= 0) {
      throw std::invalid_argument("Fee value must be a positive number");
   }
   fees_owed += amount;
}

void Patron::reduce_fee_owed(const int amount)
{
   if (amount <= 0) {
      throw std::invalid_argument("amount value must be a positive number");
   }

   // Exercise description does not state what should happen in this case.
   // So I just throw an exception
   if (fees_owed - amount < 0) {
      throw std::runtime_error("Fees_owed will become a negative number");
   }

   fees_owed -= amount;
}
