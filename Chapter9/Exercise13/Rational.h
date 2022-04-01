#ifndef EXERCISE13_RATIONAL_H
#define EXERCISE13_RATIONAL_H

class Rational {
public:
   /// @throws std::invalid_argument if given denominator value is 0
   Rational(int numerator, int denominator);

   /// @returns The equivalent double representation;
   double to_double() const { return static_cast<double>(numerator) / denominator; }

   /// Does not return the simplest possible result.
   Rational operator+(const Rational& other) const {
      return Rational{(numerator * other.denominator) + (other.numerator * denominator),
                      denominator * other.denominator};
   }

   /// Does not return the simplest possible result.
   Rational operator-(const Rational& other) const {
      return Rational{(numerator * other.denominator) - (other.numerator * denominator),
                      denominator * other.denominator};
   }

   /// Does not return the simplest possible result.
   Rational operator*(const Rational& other) const {
       return Rational{numerator * other.numerator, denominator * other.denominator};
   }

   /// Does not return the simplest possible result.
   Rational operator/(const Rational& other) const {
      return *this * Rational{other.denominator, other.numerator};  // x / y == x * 1/y
   }

   bool operator==(const Rational& other) const {
      return to_double() == other.to_double();
   }

private:
   int numerator;
   int denominator;
};

#endif // EXERCISE13_RATIONAL_H
