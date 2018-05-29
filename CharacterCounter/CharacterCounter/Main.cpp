#include <iostream>
#include "CharacterCounter.h"


int main(int argc, char* argv[])
{

	CharacterCounter lCounter;

	unsigned char lChar;

	while (std::cin >> lChar)
	{
		lCounter.count(lChar);
	}

	std::cout << lCounter;

	return 0;
}