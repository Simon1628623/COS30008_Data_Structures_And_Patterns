#pragma once

#include <iostream>
#include <ostream>


class HexBlock
{
private:
	unsigned char fBuffer[16];
	unsigned long fSize;

public:
	//default constructor set buffer elements to zero and size to 16
	HexBlock();

	//read up to 16 bytes(raw chars) into buffer
	//records number of chars read in size (<= 16)
	std::istream& read(std::istream& aIStream);

	//getter to return chars in buffer
	unsigned long size() const;

	//formatted output operator producing a hex dump line
	friend std::ostream& operator<<(std::ostream& aOStream, const HexBlock& aObject);
};