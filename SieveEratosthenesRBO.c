#include "SieveEratosthenesRBO.h"

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

void freeSieve(struct sieve_t* sv)
{
	free(sv->mod1);
	sv->mod1 = NULL;

	free(sv->mod5);
	sv->mod5 = NULL;

	sv->n = 0;
}
