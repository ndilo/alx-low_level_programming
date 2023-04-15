#include <stdio.h>

/**
 * main - prints all arguments it receives.
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	int j;

	for (j = 0; j < argc; j++)
		printf("%s\n", argv[j]);

	return (0);
}
