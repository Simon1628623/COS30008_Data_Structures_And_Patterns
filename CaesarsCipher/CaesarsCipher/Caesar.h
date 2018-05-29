#pragma once

#include <iostream>
#include <fstream>


class Caesar
{
private:
	int fCharacterFrequenciesBefore[26];
	int fCharacterFrequenciesAfter[26];

public:
	Caesar();

	void shiftByFour(std::ifstream& aInput, std::ofstream& aOutput);

	//prints the character frequencies
	friend std::ostream& operator<< (std::ostream& aOStream, const Caesar& aObject); 
	
};