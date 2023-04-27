#include<stdio.h>

/**
 * myFirst - Apply the constructor attribute to myFirst() so that it
 *   is executed before main()
 */
void myFirst(void) __attribute__ ((constructor));

/**
 * myFirst - implementation of myFirst
 */
void myFirst(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
