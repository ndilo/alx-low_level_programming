#include "main.h"

/**
 * cap_string - capitalizes all words in a string
 * @s: string
 * Return: address of s
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char a[] = " \t\n,;.!?\"(){}";

	while (*(s + i))
	{
		if (*(s + i) >= 97 && *(s + i) <= 122)
		{
			if (i == 0)
				*(s + i) = *(s + i) - 32;
			else
			{
				for (j = 0; j <= 12; j++)
				{
					if (a[j] == *(s + i - 1))
						*(s + i) = *(s + i) - 32;
				}
			}
		}
		i++;
	}
	return (s);
}
