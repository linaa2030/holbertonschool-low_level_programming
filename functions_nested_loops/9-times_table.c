#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row = 0;
	int col;
	int p;

	while (row <= 9)
	{
		col = 0;
		while (col <= 9)
		{
			p = row * col;
			if (col == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 10)
				{
					_putchar(' ');
					_putchar(p + '0');
				}
				else
				{
					_putchar((p / 10) + '0');
					_putchar((p % 10) + '0');
				}
			}
			col++;
		}
		_putchar('\n');
		row++;
	}
}
