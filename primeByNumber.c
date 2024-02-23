#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "SieveEratosthenesRBO.h"

unsigned long long sieve_bound(unsigned num)
{
	double bound, dNum;
	assert(num > 13);

	dNum = num;
	bound = dNum * (log(dNum) + log(log(dNum)));

	return (unsigned long long) round(bound);
}

int main()
{
	unsigned long long number, sieveBound;
	struct sieve_t* sieve;

	int parScanf;
	
	parScanf = scanf("%llu", &number);
	printf("%llu'th", number);

	if (parScanf != 1)
		abort();
		
	if (number == 1)
		printf(" prime num is %u\n", 2);
		
	if (number == 2)
		printf(" prime num is %u\n", 3);

	if (number > 2)
	{
		if (number > 13)
			sieveBound = sieve_bound(number);
		else
			sieveBound = 49;

		sieve = createSieve(sieveBound);
		printf(" prime num is %llu\n", primeNumFromSieveByNumber(number, sieve));

		freeSieve(sieve);
	}
	
	return 0;
}
