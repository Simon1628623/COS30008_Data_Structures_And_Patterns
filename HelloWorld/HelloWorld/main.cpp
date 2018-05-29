//include the definition of console I/O. We are using two I/O values, cout and endl
#include <iostream>

//telling C++ to look for all library names in namespace std
using namespace std;

//argc contains a number of arguments in this case the number of arguements aka elements in the array argv.
//argv contains an arra of C strings (char arrays) the element at i 0 is always the name of the command
int main (int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}

	return 0;
}