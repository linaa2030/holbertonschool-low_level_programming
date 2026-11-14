#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @s: String to encode.
 *
 * Return: Pointer to the modified string.
 */
char *rot13(char *s)
{
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encoded[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = encoded[j];
				break;
			}
		}
	}

	return (s);
}
