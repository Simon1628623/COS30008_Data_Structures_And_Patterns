#include "CharacterCounter.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "arguements missing" << endl;
		return 1;
	}
	
	ifstream lInput; //declaring an input file

	lInput.open(argv[1], ifstream::in); //opens input text file

	if (!lInput.good()) //making sure input has no errors and reading correctly
	{
		cerr << "Cannot open input file" << argv[1] << endl;
		return 2;
	}

	ofstream lOutput; // declaring output file

	lOutput.open(argv[2], ofstream::out); // opens output text file

	if (!lOutput.good()) //making sure output has no errors and reading correctly
	{
		cerr << "Cannot open output file " << argv[2] << endl;
		lInput.close(); //must close input
		return 3;
	}


	CharacterCounter lCOunter;

	unsigned char lChar;

	while (lInput >> lChar) //while input file still has characters
	{
		lCOunter.count(lChar);
	}

	cout << lCOunter; //displaying otuput file
	lOutput << lCOunter; // putting results into output file

	//make sure to always close inputs/outputs
	lInput.close();
	lOutput.close();

	
	/*
	CharacterCounter lCounter;

	unsigned char lChar;

	while ( cin >> lChar )
	{
		lCounter.count( lChar );
	}

	cout << lCounter;
	*/
	

	return 0;
}
