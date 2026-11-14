#include "main.h"

/**
 * set_string - Sets a pointer to a string.
 * @s: Pointer to the string pointer to update.
 * @to: String to point to.
 *
 * Return: Nothing.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
