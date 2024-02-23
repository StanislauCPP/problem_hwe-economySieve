#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "SieveEratosthenesRBO.h"

int main()
{
	unsigned long long num;
	struct sieve_t *sieve;
	int parScanf;

	parScanf = scanf("%llu", &num);
	if(parScanf != 1)
		abort();
	
	sieve = createSieve(num);
	
	if(is_prime(sieve, num))
		printf("%llu is prime\n", num);
	else
		printf("%llu is not prime\n", num);
	
	freeSieve(sieve);

	return 0;
}
