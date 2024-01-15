#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "SieveEratosthenesRBO.h"

void initSetSieve(unsigned long long num, struct sieve_t* sv)
{
	sv->n = num / 48 + 1;
	initSieve(sv);
	fill_sieve(sv);
}

int main()
{
	unsigned long long num;
	struct sieve_t sieve;
	int parScanf;

	parScanf = scanf("%llu", &num);
	if(parScanf != 1)
		abort();
	
	initSetSieve(num, &sieve);
	
	if(is_prime(&sieve, num))
		printf("%llu is prime\n", num);
	else
		printf("%llu is not prime\n", num);
	
	freeSieve(&sieve);

	return 0;
}
