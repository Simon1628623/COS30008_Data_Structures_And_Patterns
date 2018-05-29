#pragma once
#include <iostream>
#include "SimpleString.h"

using namespace std;

SimpleString::SimpleString()
{
	fCharacters = new char[1];
	*fCharacters = '\0';
}

SimpleString::~SimpleString()
{
	delete fCharacters;
}

//copy constructor to make a deep copy aka not a pointer to old copy
//deep copy allocating new memory and new pointer to instance
SimpleString::SimpleString(const SimpleString& aOtherString)
{
	int lLength = strlen(aOtherString.fCharacters) + 1;
	fCharacters = new char[lLength];

	for (unsigned int i = 0; i < lLength; i++)
		fCharacters[i] = aOtherString.fCharacters[i];
}

//initializing instance variables after releasing previous memory
SimpleString& SimpleString::operator=(const SimpleString& aOtherString)
{
	if (&aOtherString != this) //protects intself from deleting itself
	{
		delete fCharacters;

		int lLength = strlen(aOtherString.fCharacters) + 1;
		fCharacters = new char[lLength];

		for (unsigned int i = 0; i < lLength; i++)
			fCharacters[i] = aOtherString.fCharacters[i];
	}
	return *this;
}

SimpleString* SimpleString::clone()
{
	return new SimpleString(*this);
}

SimpleString& SimpleString::operator+(const char aCharacter)
{
	char *Temp = new char[strlen(fCharacters) + 2];
	unsigned int i = 0;

	for (; i < strlen(fCharacters); i++)
		Temp[i] = fCharacters[i];

	Temp[i++] = aCharacter;
	Temp[i] = '\0';

	delete fCharacters;
	fCharacters = Temp;
	return *this;
}

const char* SimpleString::operator*() const
{
	return fCharacters;
}