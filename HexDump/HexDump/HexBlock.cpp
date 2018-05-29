#include "HexBlock.h"

//default constructor set buffer elements to zero and size to 16
HexBlock::HexBlock() : fBuffer(), fSize(16){}

//read up to 16 bytes(raw chars) into buffer and records number of chars read in size (<= 16)
std::istream& HexBlock::read(std::istream& aIStream)
{
	// read data as a block and Returns the number of characters extracted from input, performed by last unformatted input operation to fSize
	fSize = (long)aIStream.read((char*)fBuffer, fSize).gcount();

	//Returns the number of characters extracted from input, performed by last unformatted input operation
	//fSize = aIStream.gcount();
		
	return aIStream;
}

//provides a getter size method that returns actual number of bytes (chars) being hosted (read from last file) (16 bytes)
unsigned long HexBlock::size() const
{
	return fSize;
}

//formatted output operator producing a hex dump line
//starts with absolute address (in hex) file pointer offset of the 16 byte data block being processed. starts at 0
//middle part uses two groups seperated by |. of 8 two digit hexadecimal numbers seperated by space
//end of line we post graphical representation of the unit a sequence of ASCII characters byte values that don't possess graphical characters will be substituted with .
std::ostream& operator<<(std::ostream& aOStream, const HexBlock& aObject)
{
	//for hex values
	for (int i = 0; i < 16; i++)
	{
		aOStream << " ";
		aOStream.width(2);
		aOStream.fill('0');
		if (aObject.size() == 16)
			aOStream << std::hex << std::uppercase << (unsigned)aObject.fBuffer[i];
		else{ aOStream << "  "; }

		if (i == 7 && aObject.size() >= 8)
		{
			aOStream << " | ";
		}
	}
	
	aOStream.width(2);
	aOStream.fill(' ');
	
	//general printable chars code
	for (int i = 0; i < (int)aObject.size(); i++)
	{
		if ((char)aObject.fBuffer[i] < 32)
			aOStream << '.';
		else{ aOStream << aObject.fBuffer[i]; }
	}
		
	return aOStream;
}