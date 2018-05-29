#include "Polynomial.h"

// calculate polynomial for a given x (i.e., parameter aX)
double Polynomial::calculate(double aX) const
{
	double Result = 0;
	for (int i = 0; i <= fDegree; i++)
	{
		//pow returns base raised to the power exponent
		//pow(double base, double exponent);
		Result += fCoeffs[i] * pow(aX, i);
	}
	return Result;
}

Polynomial Polynomial::buildIndefiniteIntegral() const
{
	// the method does not change the current object
	Polynomial Result;
	// the indefinite integral is a fresh polynomial with degree fDegree+1
	Result.fDegree = fDegree + 1;

	//loop from fDegree to 0
	for (int i = fDegree; i >= 0; i--)
	{
		Result.fCoeffs[i + 1] = (fCoeffs[i] / (1 + i));
	}
	return Result;
}

double Polynomial::buildDefiniteIntegral(double aXLow, double aXHigh) const
{
	double Result = 0;
	Polynomial indefInt;

	for (int i = 1; i <= fDegree; i++)
	{
		if (fCoeffs[i] != 0)
		{
			// the method computes the indefinite integral and then calculates it
			// for xlow and xhigh and returns the difference
			indefInt = buildIndefiniteIntegral();
			//Result += (indefInt.fCoeffs[i + 1] * pow(aXHigh, (1 + i))) - (indefInt.fCoeffs[i + 1] * pow(aXLow, (1 + i)));
			Result += indefInt.calculate(aXHigh) - indefInt.calculate(aXLow);
		}
	}
	return Result;
}