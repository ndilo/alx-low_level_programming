#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - structure of type dog
 * @d: pointer to structure
 * @name: name of the dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
