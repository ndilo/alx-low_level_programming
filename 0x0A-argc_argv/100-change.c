#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* main - prints the minimum number of coins to
* make change for an amount of money
* @argc: arguments count
* @argv: array of arguments
* Return: Always 0 (Success), 1 (Error)
*/

int main(int argc, char *argv[])

{
	int num, y, result;

	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)

	{
		printf("Error\n");

		return (1);
	}
	num = atoi(argv[1]);
	result = 0;
	if (num < 0)
	{
		printf("0\n");
		return (0);
	}

	for (y = 0; y < 5 && num >= 0; y++)
	{
		while (num >= coins[y])
		{
			result++;
			num -= coins[y];
		}
	}
	printf("%d\n", result);
	return (0);
}
