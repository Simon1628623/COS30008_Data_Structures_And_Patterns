#include "Polynomial.h"

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
		if (aObject.fCoeffs[i + 1] == 0){}
		else if (i < aObject.fDegree){ aOStream << aObject.fCoeffs[i + 1] << "x^" << i << " + "; }
		else{ aOStream << aObject.fCoeffs[i + 1] << "x^" << i; }
		
		
	}
	return aOStream;
}


