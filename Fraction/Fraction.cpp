#include "Fraction.h"

using namespace Ratio;

Fraction::Fraction(int numer, int denom)
{
	if (denom <=0)
		throw std::runtime_error ("denominator is not valid");
	int a = nod (numer, denom);
	numerator = numer / a;
	denominator = denom / a;	
}

int Fraction::nod (int numer, int denom)
{
	if (numer < 0)
		numer = numer * (-1);
	int k = numer % denom;
	if (k==0)
		return denom;	
	return nod (denom, k);
}	

int Fraction::getNumer ()
{
	return this->numerator;
}

int Fraction::getDenom ()
{
	return this->denominator;
}

Fraction Fraction::operator+ (const Fraction& rhs) const
{
	return Fraction ((this->numerator * rhs.denominator) + (rhs.numerator * this->denominator), this->denominator * rhs.denominator);
}

Fraction Fraction::operator+ (int a) const
{
	return Fraction (this->denominator * a + this->numerator, this->denominator);
}

string Fraction::FractionInfo ()
{
	stringstream ss;
	ss << this->numerator << "/" << this->denominator;
	return ss.str();
}

void Fraction::printFraction ()
{
	cout << FractionInfo () << endl;
}

Fraction Fraction::operator- (const Fraction& rhs) const
{
	return Fraction ((this->numerator * rhs.denominator) - (rhs.numerator * this->denominator), this->denominator * rhs.denominator);
}

Fraction Fraction::operator- (int a) const
{
	return Fraction (this->numerator - (this->denominator * a), this->denominator);
}

Fraction Fraction::operator* (const Fraction& rhs) const
{
	return Fraction (this->numerator * rhs.numerator, this->denominator * rhs.denominator);
}

Fraction Fraction::operator* (int a) const
{
	return Fraction (this->numerator * a, this->denominator);
}

Fraction Fraction::operator/ (const Fraction& rhs) const
{
	return Fraction (this->numerator * rhs.denominator, this->denominator * rhs.numerator);
}

Fraction Fraction::operator/ (int a) const
{
	return Fraction (this->numerator, this->denominator * a);
}

Fraction::operator int() const
	{
		return numerator / denominator;
	}