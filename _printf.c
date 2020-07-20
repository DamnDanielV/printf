#include "holberton.h"
/**
 * _printf - own printf function
 * @format: the format specifier string
 *
 * Return: number of characters print
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int (*func)(va_list), i = 0, c = 0;

	va_start(arguments, format);

	if (format == '\0')
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			func = match_parameter(format[i]);
			if (func == NULL)
				c += c_n(format[i]);
			else
				c += func(arguments);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
			}
		else
		{
			_putchar(format[i]);
		c++;
		}
		i++;
	}
	va_end(arguments);
	return (c);
}

/**
 * c_n - print number
 * @ch: number to be print
 * Return: number of chars printed
 */
int c_n(char ch)
{
	switch (ch)
	{
	case '%':
		_putchar(ch);
		return (1);
	case ' ':
		_putchar(ch);
		return (1);
	}
	return (0);
}

/**
 * match_parameter - find a parameter
 * @s: parameter
 * Return: NULL or to function
 */
int (*match_parameter(char s))(va_list)
{
	str_speci options[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_number},
		{'i', print_number},
		{'u', printu},
		{'\0', NULL}
	};
	int i = 0;

	while (options[i].ch != '\0')
	{
		if (options[i].ch == s)
			return (options[i].fu_pr);
		i++;
	}
	return (NULL);
}
