#pragma once

#include <fstream>
#include <string>
#include "HexBlock.h"
//#include <iomanip>

class HexDump
{
private:
	HexBlock fData;
	std::ifstream fInput;

public:
	//open input file
	bool open(const std::string& aInputFileName);

	//close input file
	void close();

	//Generate hex dump to standard output.
	//repeatedly read a HexBLock (16 bytes) and produce corresponding hex dump line consisting of offset and hex dump line for HexBlock object fData
	//the method should utilize a do while loop and run as lng as the sizeOf fData is 16.
	//maintain a long counter to generate offsets. increment by 16
	//in do while loop fData reads the next data block and corresponding hex dump line is sent to standard output.
	//loop stops if either no data was read or when less than 16 bytes were read overall
	void processInput();

	//make objects of type HexDump callable.
	//we use objects of type HexDump as functions that take a file name as parameter and return a bool to indicate success or
	//failure of producing a hex dump to standard output.
	//the result is false only if we could not open input.
	//if true we can open input file
	//
	bool operator()(const std::string& aInputFileName);
};