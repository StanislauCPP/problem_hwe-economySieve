#include "SieveEratosthenesBO.h"

struct sieve_t
{
	unsigned long long n;
	unsigned char* s;
};

void fill_sieve(struct sieve_t* sv);
struct sieve_t* createSieve(unsigned long long num)
{
	struct sieve_t* sieve;
	sieve = malloc(sizeof(struct sieve_t));
	if (sieve == NULL)
		abort();

	sieve->n = (num / 8) + 1;
	sieve->s = calloc(sieve->n, sizeof(unsigned char));

	fill_sieve(sieve);

	return sieve;
}

void fill_sieve(struct sieve_t* sv)
{
	unsigned long long bitsAmount = 0, i = 2, bitsInByte = 8, j = 0, bytesAmount;
	unsigned char* sieve = sv->s;
	bytesAmount = sv->n;
	bitsAmount = bytesAmount * bitsInByte;

	sieve[0] = 3;			//set first and second bits to 1

	for (i = 2; i < bitsAmount; ++i)
	{
		if ((sieve[i / bitsInByte] >> (i % bitsInByte)) & 1)
			continue;

		for (j = i * i; j < bitsAmount; j = j + i)
		{
			sieve[j / bitsInByte] = sieve[j / bitsInByte] | (1 << (j % bitsInByte));
		}
	}
}

int is_prime(struct sieve_t* sv, unsigned long long n)
{
	unsigned long long bitsInByte = 8, bitsAmount;
	bitsAmount = bitsInByte * sv->n;
	assert(n < bitsAmount);

	return(!((sv->s[n / bitsInByte] >> (n % bitsInByte)) & 1));
}

unsigned primeCountInByte(unsigned char byte)
{
	unsigned count = 8;

	for (byte; byte != 0; byte = byte & (byte - 1))
		--count;

	return count;
}

unsigned long long primeNumFromSieveByNumber(struct sieve_t* sv, unsigned long long n)
{
	unsigned long long i = 0, j;
	unsigned count;

	for (i; n > 16; ++i)
	{
		count = primeCountInByte(sv->s[i]);
		n -= count;
	}

	for (i; n != 0; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			n -= !((sv->s[i] >> j) & 1);
			if (!n)
				return ((i*8 + j));
		}
	}

	abort();
}

void freeSieve(struct sieve_t* sv)
{
	free(sv->s);
	sv->s = NULL;
	sv->n = 0;

	free(sv);
	sv = NULL;
}
