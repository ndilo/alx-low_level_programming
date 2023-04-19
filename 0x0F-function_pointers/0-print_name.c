#include "function_pointers.h"

/**
 * print_name - function to prints a name.
 * @name: the name
 * @f: function of the name
 *
 * Rteurn: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)

		f(name);
}
