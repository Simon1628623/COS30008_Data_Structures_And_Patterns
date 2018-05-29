#include "IntArrayIterator.h"


int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int Sum = 0;

    //works as for each loop
	for (IntArrayIterator iter(a, 5); iter != iter.end(); iter++)
		Sum += *iter;

	cout << "Iterated sum of [1,2,3,4,5] is" << Sum << endl;

	return 0;
}