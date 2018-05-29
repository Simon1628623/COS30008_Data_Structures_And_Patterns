#include "Caesar.h"

Caesar::Caesar() : fCharacterFrequenciesBefore(), fCharacterFrequenciesAfter()
{
	
}

void Caesar::shiftByFour(std::ifstream& aInput, std::ofstream& aOutput)
{
	//initialize it with get a single character from aInput;
	char lOldChar; //= aInput.get(char);
	aInput.get(lOldChar);


	char lNewChar;

	//while aInput is good do
	while (aInput.good())
	{
		//if lOldChar is alphabetic then
		if (isalpha(lOldChar))
		{
			//assign lOldChar result of converting lOldChar to uppercase;
			lOldChar = toupper(lOldChar);
			//count(before) frequency of lOldChar; // index lOldChar – ‘A’
			for (int i = 26; i > -1; i--)
			{
				if (i == lOldChar - 'A')
					fCharacterFrequenciesBefore[i]++;
			}
			
			//assign lNewChar result of ’A’ + ((lOldChar – ‘A’ + 4) % 26);
			//lNewChar = 'A' + ((lOldChar – 'A' + 4) % 26);
			lNewChar = 'A' + ((lOldChar - 'A' + 4) % 26);
			//count(after) frequency of lNewChar; // index lNewChar – ‘A’
			for (int i = 26; i > -1; i--)
			{
				if (i == lNewChar - 'A')
					fCharacterFrequenciesAfter[i]++;
			}
			//if lLower then
			if (!islower(lNewChar))
			{
				//assign lNewChar result of converting lNewChar to lowercase;
				lNewChar = tolower(lNewChar);
			}
			//put lNewChar to aOutput;
			aOutput << lNewChar;
		}
		else
		{
			//put lOldChar to aOutput;
			aOutput << lOldChar;
		}

		// get a single character from aInput and assign it to lOldChar;
		//lOldChar; //= aInput.get(char);
		aInput.get(lOldChar);
	}
}

//prints character frequencies
std::ostream& operator<< (std::ostream& aOStream, const Caesar& aObject)
{
	//CHaracter frequencies <before, after>:
	//A: 129, 25
	//B: 29, 0
	//etc

	aOStream << "Character frequencies <before, after>:" << std::endl;
	for (int i = 0; i < 26; i++)
	{
		aOStream << (char)('A' + i) << ": " << aObject.fCharacterFrequenciesBefore[i] << " , " << aObject.fCharacterFrequenciesAfter[i] << std::endl;
	}

	return aOStream;
}

