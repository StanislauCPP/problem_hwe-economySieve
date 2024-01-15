#include "../../SieveEratosthenesRBO.h"
#include "TestFunction.h"
#include "Timer.h"

void setBenchmarkSieve(unsigned long long num, unsigned char* mod)
{
	unsigned long long i;
	int bit;

	for (i = 0; (i * 6) < num; ++i)
	{
		scanf("%d", &bit);
		if (bit)
		{
			mod[i / 8] = mod[i / 8] | (bit << i % 8);
		}
	}
}

void initSetBenchmark(unsigned long long num, struct sieve_t* sv)
{
	sv->n = (num / 48) + 1;
	initSieve(sv);
	setBenchmarkSieve(num, sv->mod1);
	setBenchmarkSieve(num, sv->mod5);
}

void initSetChackableSieve(unsigned long long num, struct sieve_t* sv)
{
	sv->n = (num / 48) + 1;
	initSieve(sv);
	fill_sieve(sv);
}

void fillSieveTestResult(struct sieve_t* benchmark, struct sieve_t* checkableSieve)
{
	int i = 0;

	printf("b - benchmark, c - checkableSieve\n");
	printf("\t\t\tbM1\tcM1\tbM5\tcM5\t\n");
	printf("first value(i = %d)\t%0x\t%0x\t%0x\t%0x\t\n", i, benchmark->mod1[i], checkableSieve->mod1[i], benchmark->mod5[i], checkableSieve->mod5[i]);

	for (i; i < checkableSieve->n; ++i)
	{
		if(benchmark->mod1[i] != checkableSieve->mod1[i])
			printf("benchmark->mod1[i] != checkableSieve->mod1[i]/t i = %d\n", i);
			
		if(benchmark->mod5[i] != checkableSieve->mod5[i])
			printf("benchmark->mod1[i] != checkableSieve->mod1[i]/t i = %d\n", i);
	
		assert(benchmark->mod1[i] == checkableSieve->mod1[i]
			&& benchmark->mod5[i] == checkableSieve->mod5[i]);
	}
	--i;

	printf("\n\t\t\tbM1\tcM1\tbM5\tcM5\t\n");
	printf("last value(i = %d)\t%0x\t%0x\t%0x\t%0x\t\n", i, benchmark->mod1[i], checkableSieve->mod1[i], benchmark->mod5[i], checkableSieve->mod5[i]);
}

void getNumInitSetChackableSieve(unsigned long long* num, struct sieve_t* sv)
{
	int parScanf;
	parScanf = scanf("%llu", num);

	if (parScanf != 1)
		abort();

	printf("num = %llu\n", (*num));

	initSetChackableSieve((*num), sv);
}

void checkFillSieve()
{
	unsigned long long num;
	struct sieve_t benchmark, checkableSieve;
	struct timespec t1, t2;
	double difference;
	
	timespec_get(&t1, TIME_UTC);
	getNumInitSetChackableSieve(&num, &checkableSieve);
	timespec_get(&t2, TIME_UTC);
	difference = diff(t1, t2);
		
	initSetBenchmark(num, &benchmark);

	fillSieveTestResult(&benchmark, &checkableSieve);

	freeSieve(&checkableSieve);
	freeSieve(&benchmark);

	printf("TestFill time = %lf\nTest passed\n", difference);
}

void isPrimeTestResult(unsigned long long num, struct sieve_t* sv)
{
	unsigned long long i = 0;
	int primeStatus;

	for (i; i <= num; ++i)
	{
		scanf("%d", &primeStatus);
		
		if(primeStatus != is_prime(sv, i))
			printf("primeStatus != is_prime(sv, i)/t i = %lld\n", i);
		
		assert(primeStatus == is_prime(sv, i));
	}
}

void checkIsPrime()
{
	unsigned long long num;
	struct sieve_t checkableSieve;
	struct timespec t1, t2;
	double difference;
	
	timespec_get(&t1, TIME_UTC);
	getNumInitSetChackableSieve(&num, &checkableSieve);
	isPrimeTestResult(num, &checkableSieve);
	timespec_get(&t2, TIME_UTC);
	difference = diff(t1, t2);

	printf("TestIs time = %lf\nTest passed\n", difference);

	freeSieve(&checkableSieve);
}
