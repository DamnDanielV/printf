#include "holberton.h"

/**
 * print_number - print number
 * @arguments: number to be print
 * Return: number of chars printed
 */
int print_number(va_list arguments)
{
	int aux, size = 1, a, b, pu_ch = 0;
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
 *printu- prints unsigned int
 *@arguments: a struct of vargs to print
 *
 *Return: int with the numbers of characters printed.
 */
int printu(va_list arguments)
{
	int i;
	unsigned int x = va_arg(arguments, unsigned int);

	i = (x == 0) ? _putchar('0') : rpu(x);
	return (i);
}
/**
 *rpu - recursive printing unsigned int.
 *@x: unsigned int number to print
 *
 *Return: Number of  printed numbers.
 */
int  rpu(unsigned int x)
{
	char c;
	int i = 0;
	char *ctable = "01234567890ABCDEF";
	int BASE = 10;

	if (x)
	{
		c = ctable[x % BASE];
		rpu(x / BASE);
		i++;
		_putchar(c);
	}
	return (i);
}
