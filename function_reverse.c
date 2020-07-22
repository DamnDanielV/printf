#include "holberton.h"

/**
 * printr - reverse a string
 * @arguments: number to be print
 * Return: number of chars
 */
int printr(va_list arguments)
{
	int i = 0;
	char *string = va_arg(arguments, char *);

	if (string == NULL)
	{
		write(1, NULL, 6);
		return (6);
	}
	i += (rpr(string));
	return (i);
}
/**
 * rpr - print reverse a string
 * @string: number to be print
 * Return: number of chars printed
 */
int rpr(char *string)
{
	int i = 0;

	if (*string == '\0')
	{
		return (i);
	}
	string++;
	i += (rpr(string));
	string--;
	_putchar(*string);
	i++;
	return (i);
}
