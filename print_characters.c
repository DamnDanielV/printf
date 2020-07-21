#include "holberton.h"
/**
 * print_char - print char with write
 * @arguments: char to be print
 *
 * Return: one
 */
int print_char(va_list arguments)
{
	unsigned int c;

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
	int i = 0;
	char *string = va_arg(arguments, char *);

	while (*string)
	{
		write(1, string, 1);
		string++;
		i++;
	}
	return (i);
}

/**
 * printS - print string with constrains
 * @arguments: char to be print
 *
 * Return: number of chars printed
 */
int printS(va_list arguments)
{
	int i = 1;
	char *string = va_arg(arguments, char *);
	char *nil = "\\x";

	while (*string)
	{
		if((0 < *string) && (*string < 32 || *string >= 127))
		{
			
			write(1, nil, 2);
			
			string++;
		}
		else
		{
		write(1, string, 1);
		string++;
		i++;
		}
	}
	return (i);
}
