#include <stdio.h>
/**
 * main - Functio
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
	{
			putchar(i + '0');
			putchar(' ');
			if (i != 9)
			{
				purchar(',');
			}
	}
	putchar('\n');
	return (0);
}
