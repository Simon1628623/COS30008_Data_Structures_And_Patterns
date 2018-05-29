#include "CharacterCounter.h"
#include "CharacterCounterIterator.h"

#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
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
    
        
    CharacterCounter lCounter;

	unsigned char lChar;

	while (lInput >> lChar)
	{
		lCounter.count(lChar);
	}

	lOutput << lCounter;

    //test iterator
	cout << "The Frequencies: " << endl;
	CharacterCounterIterator iter(lCounter);
	for (CharacterCounterIterator iter(lCounter); iter != iter.end(); iter++)
	{
		cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
	}

	//make sure to always close inputs/outputs
	lInput.close();
	lOutput.close();
    
    return 0;
}