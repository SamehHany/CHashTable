#include <stdio.h>
#include <string.h>
#include "hashtable.h"
#include <limits.h>

int main()
{
//#if (defined _WIN32 || defined __WIN64)    /* WIN32 OR WIN64 SYSTEM */
	srand(time(NULL));
//#elif defined __unix__          /* in the case of unix system */

//#endif	
	/*long int x;
	scanf("%ld", &x );
	HashTable *T = newHtOfSize(x, 1);
	printf("Size of Hash Table: %ld\n", T->table_size);
	deleteHt(T);*/
	printf("ULONG_MAX: %lu\n", ULONG_MAX);
	/*_randbyte = rand() % 256;
	_randword = (int long)rand();
	
	char *str1 = malloc(100);
	char *str2 = malloc(100);
	scanf("%s", str1);
	printf( "Prehash of \"%s\": %lu\n", str1, prehash( str1, strlen(str1) ) );
	scanf("%s", str2);
	printf( "Prehash of \"%s\": %lu\n", str2, prehash( str2, strlen(str2) ) );*/
	
	return 0;
}
