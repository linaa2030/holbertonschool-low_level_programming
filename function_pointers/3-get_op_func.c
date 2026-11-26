#include "3-calc.h"
#include <stddef.h>
#include <string.h>

/**
 * get_op_func - Selects the correct operation
 * @s: Operator
 *
 * Return: Pointer to the selected function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (s != NULL && ops[i].op != NULL)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
