//
// Created by Mustafa on 5/24/2022.
//

#include "Money.h"
#include <iomanip>
#include <ostream>
#include <stdexcept>

Money::Money(const long int cents_total) : cents_total{cents_total}
{
   if (cents_total < 0) {
      throw std::invalid_argument("A monetary amount cannot be negative");
   }
}

Money::Money(const long int dollars, const int cents)
    : cents_total{dollars * 100 + cents}
{
   if (dollars < 0 || cents < 0) {
      throw std::invalid_argument("A monetary amount cannot be negative");
   }
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
   return os << '$' << m.get_dollars() << '.' << std::setfill('0') << std::setw(2)
             << m.get_cents();
}

Money operator+(const Money& m1, const Money& m2)
{
   return Money{m1.get_cents_total() + m2.get_cents_total()};
}
Money operator-(const Money& m1, const Money& m2)
{
   // Exercise does not mention what should happen with negative amounts
   // so just returning zero if result is negative

   const long int result = m1.get_cents_total() - m2.get_cents_total();
   if (result < 0) {
      return Money{0};
   }
   else {
      return Money{result};
   }
}
