#ifndef EXERCISE14_MONEY_H
#define EXERCISE14_MONEY_H

#include <iosfwd>

class Money {
public:
   Money(long int cents_total);
   Money(long int dollars, int cents);
   int get_dollars() const { return cents_total / 100; }
   int get_cents() const { return cents_total % 100; }
   int get_cents_total() const { return cents_total; }

private:
   long int cents_total = 0; // The total is stored as cents per exercise description
};

std::ostream& operator<<(std::ostream& os, const Money& m);
Money operator+(const Money& m1, const Money& m2);
Money operator-(const Money& m1, const Money& m2);

#endif // EXERCISE14_MONEY_H
