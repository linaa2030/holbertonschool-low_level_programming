#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings using at most n chars from s2
 * @s1: first string
 * @s2: second string
 * @n: maximum number of chars to copy from s2
 *
 * Return: new allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	size_t len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (len2 < n && s2[len2] != '\0')
		len2++;

	if (len1 >= (size_t)-1 - len2)
		return (NULL);

	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];
	for (j = 0; j < len2; j++)
		result[i + j] = s2[j];
	result[i + j] = '\0';

	return (result);
}
