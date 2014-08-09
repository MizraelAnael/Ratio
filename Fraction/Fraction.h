#pragma once

#include <string>
#include <iostream>
#include <sstream> 

using namespace std;

namespace Ratio
{
	class Fraction
	{
	private:
		int nod (int numer, int denom);		
	public:
		Fraction (int numer, int denom);	
		//Fraction operator= (const Fraction& rhs) = default;
		//Fraction (const Fraction& rhs) = default;
		Fraction operator+ (const Fraction& rhs) const;
		Fraction operator+ (int) const;
		Fraction operator- (const Fraction& rhs) const;	
		Fraction operator- (int a) const;
		Fraction operator* (const Fraction& rhs) const;	
		Fraction operator* (int a) const;
		Fraction operator/ (const Fraction& rhs) const;
		Fraction operator/ (int a) const;
		string FractionInfo ();
		void printFraction ();
		int getNumer ();
		int getDenom ();
		operator int() const; //Get integer
	private:
		int numerator;
		int denominator;
	};
}