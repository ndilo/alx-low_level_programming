#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */
/**
 * main - function
 *
 * Return: Always 0
 */
/* betty style doc for function main goes there */
void positive_or_negative(int n)
{
        /* your code goes there */
        if (n > 0)
                printf("%d is positive", n);
        else if (n == 0)
                printf("%d is zero", n);
        else
                printf("%d is negative", n);
        printf("\n");
        return;
}
