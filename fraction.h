#include <iostream>
using namespace std;

struct Fraction {
   int num;
   int den;
};

// A function to calculate the greatest common divisor will be useful
int gcd(int a, int b)
{
	if( b == 0 )
		return a;
	return gcd(b,a%b);
}

// All fraction values are reduced
// For example, we have 3/4 and never 9/12
// It would be good to create a function to do that
void reduce(Fraction &f)
{
	int greatestCommonDen = gcd(f.num, f.den);
  f.num = f.num / greatestCommonDen;
  f.den = f.den / greatestCommonDen;
  if(f.den < 0) //makes sure the den isn't negative/reduces correctly if both are negative from mult/div
  {
    f.den *= -1;
    f.num *= -1;
  }
}

istream& operator>>(istream& in, Fraction &f)
{
    // Implement fraction input here
    char filler; //filler char
    in >> f.num >> filler >> f.den;
    reduce(f);
    return in;
}

ostream& operator<<(ostream& out, Fraction f)
{
    // Implement fraction output here
    out << f.num << "/" << f.den;
    return out;
}

Fraction operator+(Fraction a, Fraction b)
{
    // Implement fraction addition here
    Fraction c;
    if(a.den == b.den) //makes sure we are adding fractions of the same base 
    {
      c.num = a.num + b.num;
      c.den = a.den;
    }
    else //adds correctly if the bases aren't the same
    {
      c.num = a.num*b.den + b.num*a.den;
      c.den = a.den*b.den;
    }
    reduce(c);
    return c;
}

Fraction operator-(Fraction a, Fraction b)
{
    // Implement fraction subtraction (a-b) here
    b.num = -b.num;
    Fraction c = a + b; //adding the opposite of one to the other = subtraction
    reduce(c);
    return c;
}

Fraction operator*(Fraction a, Fraction b)
{
    // Implement fraction multiplication here
    Fraction c;
    c.num = a.num * b.num; //how fraction multiplication works
    c.den = a.den * b.den;
    reduce(c);
    return c;
}

Fraction operator/(Fraction a, Fraction b)
{
    // Implement fraction division (a/b) here
    Fraction c;
    c.num = a.num * b.den; //inverse fraction multiplication
    c.den = b.num * a.den;
    reduce(c);
    return c;
}