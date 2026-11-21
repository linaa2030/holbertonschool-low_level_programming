#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: first integer
 * @max: last integer
 *
 * Return: pointer to the array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	unsigned int difference;
	size_t count, i;

	if (min > max)
		return (NULL);

	difference = (unsigned int)max - (unsigned int)min;
	count = (size_t)difference + 1;

	if (count == 0 || count > (size_t)-1 / sizeof(int))
		return (NULL);

	array = malloc(count * sizeof(int));
	if (array == NULL)
		return (NULL);

	array[0] = min;

	for (i = 1; i < count; i++)
		array[i] = array[i - 1] + 1;

	return (array);
}
