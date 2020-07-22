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
	if (c >= INT_MAX)
	{
		return (0);
	}
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
	if (string == NULL)
	{
		write(1, "(null)", 6);
		exit(6);
	}


	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
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
	int i = 0;
	char *string = va_arg(arguments, char *);
	char *nil = "\\x";

	if (string == NULL)
	{
		write(1, "(null)", 6);
		exit(6);
	}
			while (*string)
			{
				if ((*string > 0) && (*string < 32 ||
						     *string >= 127))
				{
					write(1, nil, 2);
					i += 2;
					if (*string <= 15)
					{
						write(1, &"0", 1);
						i++;
					}
					i += (rpuu(*string, 16, 1));
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
