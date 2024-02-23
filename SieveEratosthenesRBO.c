#include "SieveEratosthenesRBO.h"

struct sieve_t {
	int n;
	unsigned char* mod1;
	unsigned char* mod5;
};

void initSieve(struct sieve_t* sv)
{	
	sv->mod1 = calloc(sv->n, sizeof(unsigned char));
	sv->mod5 = calloc(sv->n, sizeof(unsigned char));

	if (sv->mod1 == NULL || sv->mod5 == NULL)
		abort();
}

void setNotPrimeBitInCertainSieve(unsigned char* sieve, unsigned long long num)
{
	unsigned long long bitsInByte = 8, ind, k;

	k = (num - num % 6) / 6;
	ind = k / bitsInByte;
	sieve[ind] = (sieve[ind] | (1 << k % bitsInByte));
}

void setNotPrimeBit(unsigned long long step, unsigned long long limit, unsigned long long step1, struct sieve_t* sv)
{
	unsigned long long j;
	unsigned char* sieve1 = sv->mod1;
	unsigned char* sieve5 = sv->mod5;

	for (j = step * step; j < limit; j = j + (step * 6))
	{
		setNotPrimeBitInCertainSieve(sieve1, j);
	}

	for (j = (step * step) + step * step1; j < limit; j = j + (step * 6))
	{
		setNotPrimeBitInCertainSieve(sieve5, j);
	}
}

void fill_sieve(struct sieve_t* sv)
{
	unsigned long long bitsAmount = 0, bitsInByte = 8, i = 5, range = 6, limit;
	limit = sv->n * bitsInByte * range;

	sv->mod1[0] = 1;
	while (i < limit)
	{
		setNotPrimeBit(i, limit, 2, sv);

		i = i + 2;
		setNotPrimeBit(i, limit, 4, sv);

		i = i + 4;
	}
}

void initSetSieve(unsigned long long num, struct sieve_t* sv)
{
	sv->n = num / 48 + 1;
	initSieve(sv);
	fill_sieve(sv);
}

struct sieve_t* createSieve(unsigned long long num)
{
	struct sieve_t *sv;
	sv = malloc(sizeof(struct sieve_t));

	initSetSieve(num, sv);

	return sv;
}

int is_prime(struct sieve_t* sv, unsigned n)
{
	unsigned long long num = n, bitsInByte = 8, k, ind;
	unsigned char* sieve1 = sv->mod1;
	unsigned char* sieve5 = sv->mod5;

	if (num == 2 || num == 3)
		return 1;

	if (num == 0 || !(num % 2) || !(num % 3))
		return 0;
	else
	{
		k = (num - num % 6) / 6;
		ind = k / bitsInByte;
		if ((num % 6) == 1)
		{
			return (!((sieve1[ind] >> k % bitsInByte) & 1));
		}
		else
			return (!((sieve5[ind] >> k % bitsInByte) & 1));
	}
}

unsigned long long primeCountInByte(unsigned char byte)
{
	unsigned long long count = 8;
	for (byte; byte > 0; byte = byte & (byte - 1))
		--count;

	return count;
}

unsigned long long primeNumFromSieveByNumber(unsigned long long number, struct sieve_t* sv)
{
	unsigned long long i, j;

	number -= 2;
	for (i = 0; number > 16; ++i)
	{
		number -= primeCountInByte(sv->mod1[i]);
		number -= primeCountInByte(sv->mod5[i]);
	}


	for (i; number != 0; ++i)
	{
		for (j = 0; j < 8 && number != 0; ++j)
		{
			number -= !((sv->mod1[i] >> j) & 1);
			if (!number)
				return (i * 48 + 6 * j + 1);
				
			number -= !((sv->mod5[i] >> j) & 1);
			if (!number)
				return (i * 48 + 6 * j + 5);
		}
	}

	abort();
}

void freeSieve(struct sieve_t* sv)
{
	free(sv->mod1);
	sv->mod1 = NULL;

	free(sv->mod5);
	sv->mod5 = NULL;

	sv->n = 0;

	free(sv);
	sv = NULL;
}
