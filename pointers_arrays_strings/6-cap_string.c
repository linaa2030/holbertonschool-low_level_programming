#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: String to capitalize.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *s)
{
	int i = 0;
	int start = 1;

	while (s[i] != '\0')
	{
		if (start && s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('a' - 'A');

		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		    s[i] == ',' || s[i] == ';' || s[i] == '.' ||
		    s[i] == '!' || s[i] == '?' || s[i] == '"' ||
		    s[i] == '(' || s[i] == ')' || s[i] == '{' ||
		    s[i] == '}')
			start = 1;
		else
			start = 0;

		i++;
	}

	return (s);
}
