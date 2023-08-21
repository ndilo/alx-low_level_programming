#include "main.h"

/**
 * _isalpha - prints alphabetic characters
 * @c: returned characters
 *
 * Return: Aways 0
 *
 **/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	
	return (0);
}
