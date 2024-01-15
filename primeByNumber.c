#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "SieveEratosthenesRBO.h"

void initSetSieve(unsigned long long num, struct sieve_t* sv)
{
	sv->n = num / 48 + 1;
	initSieve(sv);
	fill_sieve(sv);
}

unsigned long long sieve_bound(unsigned num)
{
	double bound, dNum;
	assert(num > 20);

	dNum = num;
	bound = dNum * (log(dNum) + log(log(dNum)));

	return (unsigned long long) round(bound);
}

int main()
{
	unsigned long long number, numByNumber, i, sieveBound;
	struct sieve_t sieve;

	int parScanf;
	
	parScanf = scanf("%llu", &number);

	if (parScanf != 1)
		abort();

	if (number > 20)
		sieveBound = sieve_bound(number);
	else
		sieveBound = (49);

	initSetSieve(sieveBound, &sieve);

	for (numByNumber = 0, i = 0; i < number; ++numByNumber)
	{
		if (is_prime(&sieve, numByNumber))
			++i;
	}

	printf("%llu'th prime num is %llu\n", number, --numByNumber);

	freeSieve(&sieve);

	return 0;
}
