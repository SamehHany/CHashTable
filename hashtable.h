#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <math.h>
#include "hashfunction.h"
#include "prime.h"

typedef struct HashNode {
	void *key;
	void *data;
	size_t key_size;
	size_t data_size;
	struct HashNode *next;
} HashNode;

HashNode *newHn();

void deleteHn(HashNode *_node);

void deleteHnAfter(HashNode *_node);

typedef struct {
	size_t table_size;
	size_t size; // strg_size: storage size
	void *data; // Hash function data. e.g: constants, random variables, prime numbers, ...
	HashNode **table;
	unsigned long int (*hash)(unsigned long int, size_t, void*);
	unsigned long int (*prehash)(void*, size_t);
} HashTable;

HashTable *newHt();

HashTable *newHtOfSize(long int size, int prime);

//HashTable *newHtOfPrimeSize(long int size);

void deleteHt(HashTable *T);

void HtInsert(HashTable *Ht, void *key, size_t key_size, void *data, size_t data_size, int prime);

void expandHt(HashTable *Ht, int prime);

void copy(void *dest, void *source, size_t size); // Size in bytes

#endif
