class SimpleString
{
private:
	char* fCharacters;

public:
	//copy control requires a copy constructor, assignment operator and destructor
	SimpleString();
	virtual ~SimpleString();//make virtual when class contains virtual function
	SimpleString(const SimpleString& aOtherString);

	//assignment operator
	SimpleString& operator=(const SimpleString& aOtherString);

	//clone can only return one type when subtype redefines clone only super type returned
	SimpleString* clone();

	SimpleString& operator+(const char aCharacter);
	const char* operator*() const;
};