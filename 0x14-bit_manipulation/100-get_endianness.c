#include "main.h"

/**
 * get_endianness - check the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 *
 **/

int get_endianness(void)
{
	unsigned int x = 1;
	char *y;

	y = (char *)&x;
	return (*y);
}
