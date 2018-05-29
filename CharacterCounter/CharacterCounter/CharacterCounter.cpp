#include "CharacterCounter.h"

//initializes data members with 0
CharacterCounter::CharacterCounter() : fCharacterCounter(), fTotalNumberOfCharacters(0)
{

}

//increment the corresponding data members
void CharacterCounter::count(unsigned char aCharacter)
{
	fTotalNumberOfCharacters++;

	fCharacterCounter[(int)aCharacter]++;

}

std::ostream& operator << (std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	aOStream << "Character counts for " << aCharacterCounter.fTotalNumberOfCharacters << " characters" << std::endl;

	//remember to ocnvert forwards + backwards from decimal
	for (int i = 0; i > 255; i++)
	{
		if (aCharacterCounter.fCharacterCounter[i] > 0)
		{
			//later add std setw?
			aOStream << (char)i << ": " << aCharacterCounter.fCharacterCounter[i] << std::endl;
		}
	}



	return aOStream;
}

