#include "TestFunction.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	unsigned char testParametr;
	int parScanf;
	
	parScanf = scanf("%c", &testParametr);
	if (parScanf != 1)
		abort();

	switch (testParametr)
	{
	case 'i':
		checkIsPrime();
		break;
	
	case 'p':
		checkPrimeNumByNumber();
		break;

	default:
		printf("Wrong test parametr\n");
		abort();
		break;
	}

	return 0;
}
