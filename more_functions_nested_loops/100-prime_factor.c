#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long n = 612852475143;
	long i = 2;

	while (i * i <= n)
	{
		if (n % i == 0)
			n = n / i;
		else
			i++;
	}
	printf("%ld\n", n);
	return (0);
}
