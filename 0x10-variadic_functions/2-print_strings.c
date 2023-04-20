#include "variadic_functions.h"

/**
 * print_strings - Prints strings passed to the function separed by separators
 * @separator: A string that is used to separate strings
 * @n: number of unnamed parameters
 * Return: Always 0
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int j;
	va_list list;

	va_start(list, n);
	if (separator == NULL)
		separator = "";

	for (j = 0; j < n; j++)
	{
		str = va_arg(list, char*);
		if (str == NULL)
			str = "(nil)";
		printf("%s", str);
		if (j < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(list);
}
