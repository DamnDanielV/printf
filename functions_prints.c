#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - writes char
 * @arguments: input char list to print
 * Return: number of chars wrote
 */
void print_char(va_list arguments)
{
	char c;

	c = va_arg(arguments, int);
	_putchar(c);
}
/**
 * print_string - writes string
 * @arguments: input list string to print
 * Return: number of chars wrote
 */
void print_string(va_list arguments)
{
	int i = 0;
	char *string = va_arg(arguments, char *);

	while (string[i] != '\0')
	{
		_putchar(*string);
		i++;
	}
}
 /**
 * print_percent - writes %
 * @arguments: input list string to print
 * Return: number of chars wrote
 */
void print_percent(va_list arguments)
{
	(void)arguments;
	_putchar('%');
}
 /**
 * print_integer - writes integers
 * @arguments: input list string to print
 * Return: number of chars wrote
 */
void print_integer(va_list arguments)
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
}
