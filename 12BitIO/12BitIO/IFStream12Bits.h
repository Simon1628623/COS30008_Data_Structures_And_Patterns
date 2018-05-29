#pragma once
#include <fstream>

class IFStream12Bits
{
private:
	std::ifstream fIStream;
	unsigned char fBuffer[32];
	int fByteCount;
	int fByteIndex;
	int fBitIndex;

    //initialize the integer member variables with sensible values
    //:fBuffer(), fByteCount(0), fByteIndex(0), fBitIndex(8)
    //fBitIndex(highToLow)
	void init();

    //fills input buffer fBuffer with the next 32 bytes and sets fByteCount to number of bytes read
	void reload();
    
	//implements mapping process. returns 0 or 1 depending on value of fBuffer[fByteIndex] & (1 << (fBitIndex - 1))
    //see how it works with experiments
    //at start check if (fByteCount == 0){reload();} then use reload() called as buffer does not contain any data before calling reload
    //next fetch the bit store and then advance fByteIndex and fBitIndex 
    //if fBitIndex(highest to lowest) reaches 0 you need to switch to the next byte in the buffer. and also decrment fByteCount
    //then finally return result
    //reverse equation from tutorial? make sure I understand equations
	int readBit();
    //basic readBit
    //read12Bits(): 12Bit =
    //declar Result : 12Bit = 0;
    //for i = 1 to 12
    //do
    //declare lBit : Bit = get bit from input
    //if(lBit == 1)
    //then Result = (1 << (i-1)) + Result; //set bit at index i
    //end
    //return result


public:
	//default constructor
    IFStream12Bits();
    //takes aFIleName
	IFStream12Bits(const char* aFileName);
	~IFStream12Bits();

	void open(const char* aFileName);
	void close();
	bool fail();
    //true if no bytes left in input stream (fByteCount == 0)(should be zero if never read anythign from fIStream)
	bool eof();

    //read 12Bit codes from the bit input stream implements the read12Bits algorithm as shown in the tutorial
    // multiply values by 2 to shift left?? 
	IFStream12Bits& operator>>(int& a12BitValue);
};