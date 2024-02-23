/*Test generator generates test fo checking function in SieveEratosthenesRBO.h (SieveEratosthenesRadikalBitOptimization)*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "TestGeneratorFunction.h"
#include "SieveEratosthenesBO.h"

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
	case 'i':
		printf("%c ", testParametr);
		testForIsPrime(num);
		break;
		
	case 'p':
		printf("%c ", testParametr);
		testForPrimeNumByNumber(num);
		break;
		
	default:
		printf("Wrong test parametr\n");
		abort();
		break;
	}
	return 0;
}
