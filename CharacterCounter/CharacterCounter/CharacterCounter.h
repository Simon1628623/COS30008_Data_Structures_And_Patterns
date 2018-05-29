#pragma once

#include <iostream>

class CharacterCounter
{
private:
	int fTotalNumberOfCharacters;
	int fCharacterCounter[256]; // counting all 256 byte values

public:
	///will record total number of counted characters
	CharacterCounter();

	//constructor initilizes all data members with 0, whereas count has to increment data members
	void count(unsigned char aCharacter);

	///operator<< should print characters that occur in the input text stream (filter 0s)
	///declaring stream output operator<< as a friend of CharCOunter
	friend std::ostream& operator << (std::ostream& aOStream, const CharacterCounter& aCharacterCounter);

};

