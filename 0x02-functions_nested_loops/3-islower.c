#include "main.h"
/**
 * _islower - Capture lower case
 *@c: is the letter to be checked
 * Return: 1 if letter is lower case
 * otherwise return 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
