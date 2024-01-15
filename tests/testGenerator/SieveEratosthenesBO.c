#include "SieveEratosthenesBO.h"

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

int is_prime(struct sieve_t* sv, unsigned n)
{
	unsigned long long bitsInByte = 8, bitsAmount;
	unsigned long long uN = n;
	bitsAmount = bitsInByte * sv->n;
	assert(n < bitsAmount);

	return(!((sv->s[uN / bitsInByte] >> (uN % bitsInByte)) & 1));
}
