#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (row = 1; row <= size; row++)
	{
		for (j = 0; j < size - row; j++)
			_putchar(' ');
		for (j = 0; j < row; j++)
			_putchar('#');
		_putchar('\n');
	}
}
