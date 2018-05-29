#pragma once

#include <iostream>

#define MAX_DEGREE 20+1 //max degree = 10 + 10 + 1 aka 0 to 20

class Polynomial
{
private:
	int fDegree; //max degree of the polynomial
	double fCoeffs[MAX_DEGREE]; //the coefficents (0..10, 0..20)

public:
	//the default constructor (initilizes all member variables)
	Polynomial();

	//binary operator* to multiple to polynomials
	//arguements are read only, signified by const
	//the operator* returns a fresh polynomial with degree i+j
	Polynomial operator* (const Polynomial& aRight) const;

	//input operator for polynomials
	//requires the degree(int) and corresponding number (degree+1) of coefficients (float)
	friend std::istream& operator>> (std::istream& aIStream, Polynomial& aObject);

	//output operator for polynomials
	friend std::ostream& operator<<(std::ostream& aOStream, Polynomial& aObject);
};