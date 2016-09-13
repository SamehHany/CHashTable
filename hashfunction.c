#include "hashfunction.h"

unsigned long int prehash(void *data, size_t size)
{
	int ws = sizeof(long int); // size of word
	if (size == ws)
		return *( (unsigned long int*)data );
	unsigned long int i, ret = 0;
	unsigned char *dataptr = (unsigned char*)data; // byte pointer to data
	unsigned char *retptr = (unsigned char*)(&ret);
	for (i = 0; i < size; i++)
		retptr[i % ws] += (dataptr[i] ^ _randbyte) + (i % 3 ? size: -size);
	return ret ^ _randword;
}

