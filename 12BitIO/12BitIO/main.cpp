#include "OFStream12Bits.h"
#include "IFStream12Bits.h"
#include <iostream>

using namespace std;

void write4096()
{
	cout << "Write 4096 codes" << endl;

	OFStream12Bits lWriter("sample.lzw");

	if (lWriter.fail())
	{
		cerr << "Error: unable to open output file" << endl;
		exit(1);
	}

	for (int i = 4096; i >= 0; i--)
	{
		lWriter << i;
	}
}

void read4096()
{
	cout << "Read 4096 codes" << endl;
    
	IFStream12Bits lInput("sample.lzw");

	if (lInput.fail())
	{
		cerr << "Error: unable to open input file!" << endl;
		exit(2);
	}

	for (int i = 4095; i >= 0; i--)
	{
		int l12BitValue; 
        
        lInput >> l12BitValue;

		if (l12BitValue != i)
		{
			cerr << "Error: Code mismatch: " << l12BitValue << " != " << i << endl;
			exit(3);
		}
	}

	if (!lInput.eof())
	{
		cerr << "Error: Input stream not exhausted" << endl;
	}
}

int main()
{
	write4096();
	read4096();
	cout << "SUCCESS" << endl;

	return 0;
}

