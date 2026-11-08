#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int num, div = 1;

	if (n < 0)
	{
		_putchar('-');
		num = (unsigned int)(-(n + 1)) + 1;
	}
	else
	{
		num = n;
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		_putchar((num / div) % 10 + '0');
		div /= 10;
	}
}
