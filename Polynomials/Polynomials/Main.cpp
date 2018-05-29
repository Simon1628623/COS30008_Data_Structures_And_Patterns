#include <iostream>

//#include "Polynomial.h"
#include "PolynomialPS1.h"

using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify first polynomial (degree followed by coefficients):" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	
	Polynomial B;
	cout << "Specify second polynomial (degree followed by coefficient):" << endl;
	cin >> B;
	cout << "B = " << B << endl;

	Polynomial C = A * B;
	cout << "C = A * B = " << C << endl;
	cin >> B;
	return 0;

	/*
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
	*/
}