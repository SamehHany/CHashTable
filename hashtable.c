#include "hashtable.h"

HashNode *newHn()
{
	HashNode *n = malloc( sizeof(HashNode) );
	n->key = 0;
	n->data = 0;
	n->next = 0;
	return n;
}

void deleteHn(HashNode *_node)
{
	if (_node != 0)
	{
		free(_node->data);
		deleteHn( _node->next );
		free(_node);
	}
}

void deleteHnAfter(HashNode *_node)
{
	if (_node != 0 && _node->next != 0)
	{
		HashNode *tmp = _node->next;
		_node->next = tmp->next;
		deleteHn(tmp);
	}
}

HashTable *newHt()
{
	return newHtOfSize(101, 0);
}

HashTable *newHtOfSize(long int size, int prime)
{
	HashTable *t = malloc( sizeof(HashTable) );
	if ( prime )
		size = generatePrimeGreaterThan(size);
	t->table_size = size;
	t->size = 0;
	t->data = 0;
	t->table = malloc ( size * sizeof(HashNode*) );
	long int i;
	for (i = 0; i < size; i++)
		t->table[i] = 0;
	t->hash = 0;
	t->prehash = 0;
	return t;
}

/*HashTable *newHtOfPrimeSize(long int size)
{
	size = generatePrimeGreaterThan(size);
	return newHtOfSize(size);
}*/

void deleteHt(HashTable *T)
{
	if (T != 0)
	{
		free( T->data );
		long int i;
		for (i = 0; i < T->table_size; i++)
			deleteHn( T->table[i] );
		free( T->table );
		free( T->hash );
		free( T->prehash );
		free( T );
	}
}

void HtInsert(HashTable *Ht, void *key, size_t key_size, void *data, size_t data_size, int prime)
{
	Ht->size++;
	if (Ht->size > Ht->table_size)
		expandHt(Ht, prime);
	unsigned long int index = (*Ht->hash)( (*Ht->prehash)(key, key_size), Ht->table_size, Ht->data );
	HashNode *n = newHn();
	n->key = malloc(key_size);
	copy( n->key, key, key_size);
	n->data = malloc(data_size);
	copy( n->data, data, data_size);
	n->next = Ht->table[index];
	Ht->table[index] = n;
}

void expandHt(HashTable *Ht, int prime)
{
	long int oldSize = Ht->table_size;
	Ht->table_size = Ht->table_size * 2;
	if ( prime )
		Ht->table_size = generatePrimeGreaterThan( Ht->table_size );
	HashNode **tmp_t = Ht->table; // tmp_t: Temporary Table
	Ht->table = malloc( Ht->table_size * sizeof(HashNode*) );
	long int i;
	for ( i = 0; i < Ht->table_size; i++)
		Ht->table[i] = 0;
	HashNode *tmp, *tmpnxt;
	unsigned long int index;
	for ( i = 0; i < oldSize; i++)
	{
		tmp = tmp_t[i];
		while (tmp != 0)
		{
			index = (*Ht->hash)( (*Ht->prehash)(tmp->key, tmp->key_size), Ht->table_size, Ht->data );
			tmpnxt = tmp->next;
			tmp->next = Ht->table[index];
			Ht->table[index] = tmp;
			tmp = tmpnxt;
		}
	}
	free( tmp_t );
}

void copy(void *dest, void *source, size_t size)
{
	long int i;
	for ( i = 0; i < size; i++)
		( (char*)dest )[i] = (char) ( (const char*)source )[i];
}
