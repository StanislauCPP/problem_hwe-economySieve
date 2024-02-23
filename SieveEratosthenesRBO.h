/*SieveEratosthenesRadikalBitOptimization*/

#ifndef SIEVEERATOSTHENESRBO_H
#define SIEVEERATOSTHENESRBO_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sieve_t;

struct sieve_t* createSieve(unsigned long long num);

/*Checks number for simplicity */
int is_prime(struct sieve_t* sv, unsigned n);

unsigned long long primeNumFromSieveByNumber(unsigned long long number, struct sieve_t* sv);

void freeSieve(struct sieve_t* sv);

#endif
