#include "SieveEratosthenesBO.h"
#include "TestGeneratorFunction.h"

void genBitsByStep(unsigned long long num, struct sieve_t* sieve, unsigned step)
{
	unsigned long long k, j;
	
	for (k = 0, j = step; j <= num; ++k, j = 6 * k + step)
	{
		printf("%d ", !is_prime(sieve, j));
	}
	printf("\n");
}

void testForFillSieve(unsigned char testParametr, unsigned long long num)
{
	struct sieve_t sieve;

	if(num < 48)
		num = 48;
	else if ((num / 48))
		num = ((num / 48) + 1) * 48;
	
	sieve.n = num/8;

	sieve.s = calloc(sieve.n, sizeof(unsigned char));
	fill_sieve(&sieve);

	printf("%c %llu\n", testParametr, --num);
	genBitsByStep(num, &sieve, 1);
	genBitsByStep(num, &sieve, 5);
	
	free(sieve.s);
}

void genPrimeStatusToNum(unsigned long long num, struct sieve_t* sieve)
{
	unsigned long long i;
	
	for (i = 0; i <= num; ++i)
	{
		printf("%d ", is_prime(sieve, i));
	}
	printf("\n");
}

void testForIsPrime(unsigned char testParametr, unsigned long long num)
{
	struct sieve_t sieve;
	sieve.n = (num/8) + 1;
	
	sieve.s = calloc(sieve.n, sizeof(unsigned char));
	fill_sieve(&sieve);
	
	printf("%c %llu\n", testParametr, num);
	genPrimeStatusToNum(num, &sieve);
	
	free(sieve.s);
}
