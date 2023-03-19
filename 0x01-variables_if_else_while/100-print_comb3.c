#include <stdio.h>
/**
 * main - Function
 *
 * Return: Always 0
 */
int main(void)
{
	int m;
	int p;

	for (m = 0 ; m < 10 ; m++)
	{
		for (p = 1; p < 10; p++)
		{
			if (m < p && m != p)
			{
				putchar(m + '0');
				putchar(p + '0');
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);

}
