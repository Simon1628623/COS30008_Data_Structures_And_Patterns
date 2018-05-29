#include "PolynomialPS1.h"
#include <cmath>

Polynomial::Polynomial() : fDegree(0), fCoeffs(){}


Polynomial Polynomial::operator* (const Polynomial& aRight) const
{
	Polynomial Result;

	Result.fDegree = fDegree + aRight.fDegree;

	for (int i = 0; i < fDegree; i++)
	{
		for (int j = 0; j < aRight.fDegree; j++)
		{
			Result.fCoeffs[i + j] += fCoeffs[i] * aRight.fCoeffs[j];
			//if (Result.fCoeffs[i + j] != 0)
			//Result.fCoeffs[i + j] = i + j;
		}

	}

	return Result;
}


std::istream& operator>> (std::istream& aIStream, Polynomial& aObject)
{
	aIStream >> aObject.fDegree;
	for (int i = 0; i < aObject.fDegree + 1; i++)
	{
		aIStream >> aObject.fCoeffs[i + 1];
	}

	return aIStream;

}

std::ostream& operator<<(std::ostream& aOStream, Polynomial& aObject)
{
	for (int i = 0; i < aObject.fDegree + 1; i++)
	{
		if (aObject.fCoeffs[i + 1] != 0)
		{
			if (i < aObject.fDegree){ aOStream << aObject.fCoeffs[i + 1] << "x^" << i << " + "; }
			else{ aOStream << aObject.fCoeffs[i + 1] << "x^" << i; }
		}


	}
	return aOStream;
}

// new methods in problem set 1
// calculate polynomial for a given x (i.e., parameter aX)
double calculate(double aX) const
{

}
// build indefinite integral
// the indefinite integral is a fresh polynomial with degree fDegree+1
// the method does not change the current object
Polynomial buildIndefiniteIntegral() const
{
	Polynomial Result;
	Result.fDegree = fDegree + 1;

	for (int i = fDegree; fDegree <= 0; i--)
	{
		//coefficent stuff here
		Result.fCoeffs[i] = pow(fCoeffs[i], (Result.fDegree)) / (Result.fDegree);
	}

	return Result;
}
// build definite integral
// the method does not change the current object
// the method computes the indefinite integral and then calculates it
// for xlow and xhigh and returns the difference
//and subtract result for xlow from that obtained by xhigh
double buildDefiniteIntegral(double aXLow, double aXHigh) const
{

	//returns base raised to the power exponent
	//pow(double base, double exponent);
	
	for (int i = 0; i < degree + 1; i++)
	{
		fCoeffs[i + 1] = Coeffs[i] / (double)(i + 1);
	}

	return 0;

}

