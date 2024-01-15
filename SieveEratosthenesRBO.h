/*SieveEratosthenesRadikalBitOptimization*/

#ifndef SIEVEERATOSTHENESRBO_H
#define SIEVEERATOSTHENESRBO_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sieve_t {
	int n;
	unsigned char* mod1;
	unsigned char* mod5;
};

void initSieve(struct sieve_t* sv);

/*Fills mod1 (6k+1 number) and mod5 (6к+5 number)*/
void fill_sieve(struct sieve_t* sv);

/*Checks number for simplicity */
int is_prime(struct sieve_t* sv, unsigned n);

void freeSieve(struct sieve_t* sv);

#endif
