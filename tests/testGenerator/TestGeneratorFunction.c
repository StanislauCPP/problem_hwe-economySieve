#include <math.h>

#include "SieveEratosthenesBO.h"
#include "TestGeneratorFunction.h"

void testForIsPrime(unsigned long long num)
{
	struct sieve_t* sieve;
	sieve = createSieve(num);
	
	printf("%llu %d\n", num, is_prime(sieve, num));
	
	freeSieve(sieve);
}

unsigned long long sieve_bound(unsigned num)
{
	double bound, dNum;
	assert(num > 4);

	dNum = num;
	bound = dNum * (log(dNum) + log(log(dNum)));

	return (unsigned long long) round(bound);
}

void testForPrimeNumByNumber(unsigned long long num)
{
	unsigned long long sieveBound;
	struct sieve_t* sieve;
	
	sieveBound = num;
	if (sieveBound > 4)
		sieveBound = sieve_bound(num);

	sieve = createSieve(sieveBound);

	printf("%llu %llu\n", num, primeNumFromSieveByNumber(sieve, num));

	freeSieve(sieve);
}
