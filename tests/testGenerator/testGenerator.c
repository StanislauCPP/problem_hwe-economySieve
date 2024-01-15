/*Test generator generates test fo checking function in SieveEratosthenesRBO.h (SieveEratosthenesRadikalBitOptimization)*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "TestGeneratorFunction.h"

int main()
{
	unsigned long long num;
	unsigned char testParametr;
	int parScanf;
	parScanf = scanf("%c %llu", &testParametr, &num);

	if (parScanf != 2)
		abort();

	switch(testParametr)
	{
	case 'f':
		testForFillSieve(testParametr, num);
		break;
		
	case 'i':
		testForIsPrime(testParametr, num);
		break;
		
	default:
		printf("Wrong test parametr\n");
		abort();
		break;
	}
	return 0;
}
