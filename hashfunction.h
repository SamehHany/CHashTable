#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

//#if (defined _WIN32 || defined __WIN64)    /* WIN32 OR WIN64 SYSTEM */
#include <time.h>
//#elif defined __unix__          /* in the case of unix system */

//#endif
#include <stdlib.h>

char _randbyte;
long int _randword;

unsigned long int prehash(void *data, size_t size);

unsigned long int _universalHash(unsigned long int);

#endif
