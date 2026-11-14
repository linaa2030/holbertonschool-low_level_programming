#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an integer array.
 * @a: Array of integers.
 * @n: Number of elements to print.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i > 0)
			printf(", ");

		printf("%d", a[i]);
	}

	printf("\n");
}
