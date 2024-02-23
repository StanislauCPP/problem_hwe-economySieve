/*SieveEratosthenesBitOptimization*/

#ifndef SIEVEERATOSTHENESBO_H
#define SIEVEERATOSTHENESBO_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct sieve_t;

struct sieve_t* createSieve(unsigned long long num);

int is_prime(struct sieve_t* sv, unsigned long long n);

unsigned long long primeNumFromSieveByNumber(struct sieve_t* sv, unsigned long long n);

void freeSieve(struct sieve_t* sv);

#endif
