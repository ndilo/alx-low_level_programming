#include "main.h"

/**
 * _isupper - checks for uppercase characters
 * @c: characters to be checked
 *
 * Return: Always 0 on success
 *
 **/
 int _isupper(int c)
 {
	 if (c >= 'A' && c <= 'Z')
		 return (1);
	 return (0);
 }
