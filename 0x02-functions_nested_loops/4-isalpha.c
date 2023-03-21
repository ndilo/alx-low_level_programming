#include "main.h"
/**
 * _isalpha - checks for alphabetic character.
 * @c: letter to b checke
 * Return: 1 if c is a letter, lowercase or uppercase
 * otherwise return 0
 */
int _isalpha(int c)
{
	if ((c >= 'a') || (c <= 'z'))
		return (1);
	else
		return (0);
}
