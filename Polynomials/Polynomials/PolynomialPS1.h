#pragma once

#include <iostream>

#define MAX_DEGREE 20+1+1 //max degree = 10 + 10 + 1 aka 0 to 20

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



	// new methods in problem set 1
	// calculate polynomial for a given x (i.e., parameter aX)
	double calculate(double aX) const;
	// build indefinite integral
	// the indefinite integral is a fresh polynomial with degree fDegree+1
	// the method does not change the current object
	Polynomial buildIndefiniteIntegral() const;
	// build definite integral
	// the method does not change the current object
	// the method computes the indefinite integral and then calculates it
	// for xlow and xhigh and returns the difference
	double buildDefiniteIntegral(double aXLow, double aXHigh) const;
};