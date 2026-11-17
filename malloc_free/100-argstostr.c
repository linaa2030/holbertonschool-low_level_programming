#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates the arguments of a program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *result;
	int i;
	size_t j, len = 1, k = 0;

	if (ac <= 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++;
	}
	result = malloc(len);
	if (result == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			result[k++] = av[i][j];
		result[k++] = '\n';
	}
	result[k] = '\0';
	return (result);
}
