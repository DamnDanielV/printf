#include "holberton.h"

/**
 * print_number - print number
 * @arguments: number to be print
 * Return: number of chars printed
 */
int print_number(va_list arguments)
{
	int aux, size = 1, a, b, pu_ch = 1;
	int n = va_arg(arguments, int);

	b = n % 10;
	n = n / 10;
	aux = n;
	if (b < 0)
	{
		b = -1 * b;
		aux = -1 * aux;
		n = -1 * n;
		_putchar('-');
		pu_ch++;
	}
	if (aux > 0)
	{
		while (aux / 10 != 0)
		{
			aux = aux / 10;
			size = size * 10;
		}
		while (size > 0)
		{
			a = n / size;
			_putchar('0' + a);
			n = n - a * size;
			size = size / 10;
			pu_ch++;
		}
	}
	_putchar('0' + b);
	return (pu_ch);
}

/**
 *printb- prints octal int
 *@arguments: a struct of vargs to print
 *
 *Return: int with the numbers of characters printed.
 */
int printb(va_list arguments)
{
	int i = 0;
	unsigned long int x = va_arg(arguments, unsigned long int);

       	i += ((x == 0) ? _putchar('0') : rpub(x, 2));
	return (i);
}
