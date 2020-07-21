#include "holberton.h"
/**
 * print_unsigned - prints unsigned int
 * @arguments: list of arguments
 * Return: char
 */
int print_unsigned(va_list arguments)
{
	int c = 0;
	unsigned int i = 0, n, aux = 1000000000;

	n = va_arg(arguments, unsigned int);
	if (n == 0)
		c += _putchar('0');
	while (i < 10)
	{
		if (n / aux != 0)
		{
			c += _putchar(((n / aux) % 10) + '0');
		}
		aux = aux / 10;
		i++;
	}
	return (c);
}
/**
 * print_ocunsi - prints unsigned int
 * @arguments: list of arguments
 * Return: char
 */
int print_ocunsi(va_list arguments)
{
	int ch = 0, i, oct_array[10];
	unsigned int number;

	number = va_arg(arguments, unsigned int);
	if (number == 0)
		ch = ch + _putchar('0');
	i = 0;
	while (number != 0)
	{
		oct_array[i] = number % 8;
		number /= 8;
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (oct_array[i] >= 0 && oct_array[i] < 9)
			ch = ch + _putchar(oct_array[i] + '0');
		i--;
	}
	return (ch);
}
