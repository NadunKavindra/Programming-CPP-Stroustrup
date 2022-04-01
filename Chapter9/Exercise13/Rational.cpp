#include "Rational.h"
#include <stdexcept>

Rational::Rational(const int numerator, const int denominator)
    : numerator{numerator}, denominator{denominator}
{
   if (denominator == 0) {
      throw std::invalid_argument("Denominator cannot be zero");
   }
}
