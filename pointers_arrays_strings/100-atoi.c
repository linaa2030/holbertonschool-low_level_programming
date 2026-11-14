#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: String to convert.
 *
 * Return: The converted integer, or 0 if no digits.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int found = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && !found)
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (found)
			break;

		i++;
	}

	return (num * sign);
}
