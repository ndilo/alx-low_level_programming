#include "main.h"

/**
 * string_toupper - change lowercase to uppercase
 * @s:string
 * Return:char
 */

char *string_toupper(char *s)
{

	int i;

	i = 0;

	while (*(s + i))
	{
		if (*(s + i) >= 97 && *(s + i) <= 122)
			*(s + i) = *(s + i) - 32;
		i++;
	}
	return (s);
}
