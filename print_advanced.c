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
    printf("%u",n);
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
 * print_unsigned - prints unsigned int
 * @arguments: list of arguments
 * Return: char
 */
 int po(va_list arguments)
 {

 }