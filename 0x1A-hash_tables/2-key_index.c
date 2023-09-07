#include "hash_tables.h"

/**
 * key_index - Computes the index of a key in a hash table array.
 * @key: The key to hash.
 * @size: The size of the array in the hash table.
 *
 * Return: The index at which the key should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash = hash_djb2(key);
    unsigned long int index = hash % size;
    return index;
}
