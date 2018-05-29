#include "IFStream12Bits.h"

//default constructor
IFStream12Bits::IFStream12Bits()
{
	init();
}

//takes aFIleName
IFStream12Bits::IFStream12Bits(const char* aFileName)
{
	init();
	open(aFileName);
}

//deconstructor
IFStream12Bits::~IFStream12Bits()
{
	close();
}

//initialize the integer member variables with sensible values
//:fBuffer(), fByteCount(0), fByteIndex(0), fBitIndex(8)
//fBitIndex(highToLow)
void IFStream12Bits::init()
{
	for (int i = 0; i < 32; i++)
	{
		fBuffer[i] = 0;
	}

	fByteCount = 0;
	fByteIndex = 0;
	fBitIndex = 8;
}

//fills input buffer fBuffer with the next 32 bytes and sets fByteCount to number of bytes read
void IFStream12Bits::reload()
{
	//fills fBuffer with 32 bytes
	fIStream.read((char*)fBuffer, 32);
	//sets fByteCount to number of bytes read
	fByteCount = fIStream.gcount();
}

//implements mapping process. returns 0 or 1 depending on value of fBuffer[fByteIndex] & (1 << (fBitIndex - 1))
//see how it works with experiments
//at start check if (fByteCount == 0){reload();} then use reload() called as buffer does not contain any data before calling reload
//next fetch the bit store and then advance fByteIndex and fBitIndex 
//if fBitIndex(highest to lowest) reaches 0 you need to switch to the next byte in the buffer. and also decrment fByteCount
//then finally return result
int IFStream12Bits::readBit()
{
	if (fByteCount == 0){ reload(); }

	if (fByteCount == 0)
	{
		throw -4;
	}
	
	int result = fBuffer[fByteIndex] & (1 << (fBitIndex - 1));
	
	fBitIndex--;

	//switch to next byte in the buffer
	if (fBitIndex == 0)
	{
		fByteCount--;
		fBitIndex = 8;
		fByteIndex++;
	}

	return result;
}

void IFStream12Bits::open(const char* aFileName)
{
	fIStream.open(aFileName, std::fstream::binary);
}
	
void IFStream12Bits::close()
{
	fIStream.close();
}
	
bool IFStream12Bits::fail()
{
	return fIStream.fail();
}
	
//true if no bytes left in input stream (fByteCount == 0)(should be zero if never read anythign from fIStream)
bool IFStream12Bits::eof()
{
	return fByteCount == 0;
}

//read 12Bit codes from the bit input stream implements the read12Bits algorithm as shown in the tutorial
//basic readBit
//read12Bits(): 12Bit =
//declare Result : 12Bit = 0;
//for i = 1 to 12
//do
//declare lBit : Bit = get bit from input
//if(lBit == 1)
//then Result = (1 << (i-1)) + Result; //set bit at index i
//od
//return result
// multiply values by 2 to shift left???????????
IFStream12Bits& IFStream12Bits::operator>>(int& a12BitValue)
{
	a12BitValue = 0;
	
	for (int i = 1; i < 12; i++)
	{
		int bit = readBit();
		if (bit == 1)
		{
			a12BitValue = (1 << (i - 1)) + a12BitValue; //set bit at index i
		}
		//a12BitValue <<= 1;
	}
	return *this;
}