#include "HexDump.h"

//opens input file
bool HexDump::open(const std::string& aInputFileName)
{
	fInput.open(aInputFileName, std::ifstream::binary); //opens input text file
	
	if (!fInput.good()) //making sure input has no errors
	{
		std::cerr << "Cannot open input file" << aInputFileName << std::endl;
		return false;
	}
	return true;
}

//close input file
void HexDump::close()
{
	fInput.close();
}

//repeatedly read a HexBlock (16 bytes) and produce corresponding hex dump line consisting of offset and hex dump line for HexBlock object fData
//loop stops if either no data was read or when less than 16 bytes were read overall
void HexDump::processInput()
{
	//maintain a long counter to generate offsets. increment by 16
	unsigned long add = 0;
	
	do
	{
		fData.read(fInput);
		
		//for address
		std::cout.width(8);
		std::cout.fill('0');
		std::cout << std::hex << add << ": ";
		add += 16;
		//hex and chars
		std::cout << fData;
		std::cout << std::endl;
	} while (fData.size() == 16);
}

//using operator() make objects of type HexDump callable.
//as functions that take a file name as parameter and return a bool to indicate success or failure of producing a hex dump to standard output.
//the result is false only if we could not open input if true we can open input file.
bool HexDump::operator()(const std::string& aInputFileName)
{
	bool result = false;

	if (open(aInputFileName) == true)
	{
		result = true;
		processInput();
		close();
	}
	
	return result;
}