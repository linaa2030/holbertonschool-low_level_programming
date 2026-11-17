#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a copy of a string in newly allocated memory
 * @str: string to duplicate
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	size_t len = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];

	copy[len] = '\0';

	return (copy);
}
