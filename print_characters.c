#include "holberton.h"
/**
 * print_char - print char with write
 * @arguments: char to be print
 *
 * Return: one
 */
int print_char(va_list arguments)
{
	unsigned char c;

	c = va_arg(arguments, unsigned int);
	_putchar(c);
	return (1);
}
/**
 * print_str - print string with write
 * @arguments: char to be print
 *
 * Return: number of chars printed
 */
int print_str(va_list arguments)
{
	int i;
	char *string = va_arg(arguments, char *);

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
	return (i);
}
