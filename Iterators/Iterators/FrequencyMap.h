#pragma once

class FrequencyMap
{
private:
	char fChar;
	int fFrequency;

public:
	FrequencyMap(); // default constructor needed when used as base type of arrays
	FrequencyMap(char aChar, int aFrequency); //initialize with concrete values

    //read only getters
	char getCharacter() const; //retrieve character
	int getFrequency() const; //retrieve frequency
};