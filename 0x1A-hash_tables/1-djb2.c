#include "hash_tables.h"

/**
 * hash_djb2 - Hash function that uses the djb2 algorithm.
 * @str: String to be hashed.
 *
 * Return: The hashed value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash = 5381; /* Initial hash value*/

    int c;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }

    return hash;
}
