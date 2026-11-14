#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords with an ASCII sum of 2772
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, remaining, slots, lower, upper, value;

	remaining = 2772;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 30; i++)
	{
		slots = 29 - i;
		lower = remaining - slots * 126;
		if (lower < 33)
			lower = 33;
		upper = remaining - slots * 33;
		if (upper > 126)
			upper = 126;
		value = lower + rand() % (upper - lower + 1);
		putchar(value);
		remaining -= value;
	}
	putchar('\n');
	return (0);
}
