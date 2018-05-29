#include "OFStream12Bits.h"

OFStream12Bits::OFStream12Bits()
{
	init();
}

OFStream12Bits::OFStream12Bits(const char* aFileName)
{
	init();
	open(aFileName);
}

OFStream12Bits::~OFStream12Bits()
{
	close();
}

void OFStream12Bits::init()
{
	for (int i = 0; i < 32; i++)
	{
		fBuffer[i] = 0;
	}

	fByteIndex = 0;
	fBitIndex = 8;
}

void OFStream12Bits::writeBit0()
{
	fBitIndex--;
	finishWriteBit();
}

void OFStream12Bits::writeBit1()
{
	fBuffer[fByteIndex] += 1 << (fBitIndex - 1);
	fBitIndex--;
	finishWriteBit();
}

void OFStream12Bits::finishWriteBit()
{
	if (fBitIndex == 0)
	{
		if (fByteIndex == 31)
		{
			fByteIndex++;
            //write full buffer to stream
			flush();
		}
		else
		{
			fByteIndex++;
			fBitIndex = 8;
		}
	}
}

void OFStream12Bits::open(const char* aFileName)
{
	fOStream.open(aFileName, std::ofstream::binary);
}

bool OFStream12Bits::fail()
{
	return fOStream.fail();
}

void OFStream12Bits::close()
{
	flush();
	fOStream.close();
}

void OFStream12Bits::flush()
{
	//                                     do we need to add last byte?
    fOStream.write((char*)fBuffer, fByteIndex + (fBitIndex % 8 ? 1 : 0));
	init();
}

OFStream12Bits& OFStream12Bits::operator<<(int a12BitValue)
{
	a12BitValue = a12BitValue & 0x0fff; // mask 12 lower bits

	for (int i = 0; i < 12; i++) //write 12 bits
	{
		if (a12BitValue & 0x01) // the current lowest bit is set
		{
			writeBit1();
		}
		else
		{
			writeBit0();
		}
		a12BitValue >>= 1; // code = code / 2 --shifting value accross
	}

	return *this;
}

