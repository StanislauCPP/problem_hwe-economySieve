/*SieveEratosthenesRadikalBitOptimization*/

#ifndef SIEVEERATOSTHENESBO_H
#define SIEVEERATOSTHENESBO_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sieve_t
{
	int n;
	unsigned char* s;
};

void fill_sieve(struct sieve_t* sv);

int is_prime(struct sieve_t* sv, unsigned n);

#endif
