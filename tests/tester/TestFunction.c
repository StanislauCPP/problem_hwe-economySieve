#include "../../SieveEratosthenesRBO.h"
#include "TestFunction.h"
#include <math.h>

void checkIsPrime()
{
	unsigned long long num;
	int primeFlag, parScanf;
	struct sieve_t* checkableSieve;

	parScanf = scanf("%llu %d", &num, &primeFlag);
	if(parScanf != 2)
		abort();
	
	checkableSieve = createSieve(num);	
	
	assert(primeFlag == is_prime(checkableSieve, num));

	printf("%llu %d", num, primeFlag);
	printf("\nTest passed\n");

	freeSieve(checkableSieve);
}

unsigned long long sieve_bound(unsigned num)
{
	double bound, dNum;
	assert(num > 13);

	dNum = num;
	bound = dNum * (log(dNum) + log(log(dNum)));

	return (unsigned long long) round(bound);
}

void checkPrimeNumByNumber()
{
	unsigned long long num, sieveBound, numberByNum;
	int parScanf;
	struct sieve_t* checkableSieve;
	
	parScanf = scanf("%llu %llu", &num, &numberByNum);
	if(parScanf != 2)
		abort();
	
	sieveBound = num;
	if (sieveBound > 13)
		sieveBound = sieve_bound(num);

	checkableSieve = createSieve(sieveBound);
	
	assert(numberByNum == primeNumFromSieveByNumber(num, checkableSieve));
	
	printf("%llu %llu", num, numberByNum);
	printf("\nTest passed\n");

	freeSieve(checkableSieve);
}
