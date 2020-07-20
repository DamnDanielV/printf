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
