#pragma once
#include <fstream>
//#include <ostream>

class OFStream12Bits
{
private:
	std::ofstream fOStream;
	unsigned char fBuffer[32];
	int fByteIndex;
	int fBitIndex;

	void init(); //initialize data members
	void finishWriteBit(); //complete write
	void writeBit0(); //write 0
	void writeBit1(); //write 1

public:
	OFStream12Bits();
	OFStream12Bits(const char* aFileName);
	~OFStream12Bits();

	void open(const char* aFileName);
	void close();
	bool fail();
	void flush();
	OFStream12Bits& operator<<(int a12BitValue);
};