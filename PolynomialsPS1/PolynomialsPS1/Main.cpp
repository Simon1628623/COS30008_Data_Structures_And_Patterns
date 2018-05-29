
// COS30008, Problem set 1, 2016

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify polynomial:" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	double x;
	cout << "Specify value of x:" << endl;
	cin >> x;

	cout << "A(x) = " << A.calculate( x ) << endl;

	cout << "Indefinite integral of A = " 
	     << A.buildIndefiniteIntegral() << endl;

	cout << "Definite integral of A(xlow=0, xhigh=12.0) = " 
	     << A.buildDefiniteIntegral( 0, 12.0 ) << endl;

	return 0;
}