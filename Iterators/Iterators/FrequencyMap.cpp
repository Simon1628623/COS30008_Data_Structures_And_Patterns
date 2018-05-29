#include "FrequencyMap.h"

// default constructor needed when used as base type of arrays
FrequencyMap::FrequencyMap(): fChar(0), fFrequency(0){}

FrequencyMap::FrequencyMap(char aChar, int aFrequency) : fChar(aChar), fFrequency(aFrequency){}

char FrequencyMap::getCharacter() const
{
	return fChar;
}

int FrequencyMap::getFrequency() const
{
	return fFrequency;
}