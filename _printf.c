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
	int i = 0, c = 0;

	va_start(arguments, format);

	if (format == '\0')
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			c += c_n(format, &i, arguments);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
		}

		else
		{
			_putchar(format[i]);
			c++;
			i++;
		}

	}
	va_end(arguments);
	return (c);
}

/**
 * c_n - print number
 * @format: format to print
 *@i: index of the format string
 *@arguments: va_list with the arguments to print
 * Return: number of chars printed
 */
int c_n(const char *format, int *i, va_list arguments)
{
	int (*func)(va_list);
	int c = 0;

		func = match_parameter(format[*i + 1]);
		if (func == NULL && format[*i + 1] != '%' &&
		    format[*i + 1] != ' ')
		{
			_putchar(format[*i]);
			c++;
			(*i)++;
		}
		else if (func == NULL && format[*i + 1] == '%')
		{
			_putchar('%');
			c++;
			(*i) += 2;
		}
		else if (func == NULL && format[*i + 1] == ' ')
		{
			func = match_parameter(format[*i + 2]);
			if (func)
			{
				c += func(arguments);
				(*i) += 3;
			}
		}
		else
		{
			c += func(arguments);
			(*i) += 2;
		}
	return (c);
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
		{'b', printb},
		{'u', print_unsigned},
		{'o', print_ocunsi},
		{'S', printS},
		{'x', printhex},
		{'X', printHEX},
		{'p', printp},
		{'\0', NULL},
	};
	int i = 0;

	while (options[i].ch != '\0')
	{
		if (options[i].ch == s)
			return (options[i].fu_pr);
		i++;
	}
	return (0);
}
