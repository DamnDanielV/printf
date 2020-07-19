#include "holberton.h"
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include<stdio.h>
/**
 * _printf - own basic printf() function
 * @format: directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0, con_spa = 1;

	va_list arguments;

	str_speci list_spe[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_integer},
		{'d', print_integer},
		{'\0', NULL}
	};

	va_start(arguments, format);

	i = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (list_spe[j].c != '\0')
		{
			if (format[i] == '%')
			{
				while (format[i + 1] != '\0' && format[i + 1] == ' ')
					con_spa++;
				i = i + con_spa;
				if (list_spe[j].c == format[i])
					list_spe[j].func(arguments);
					i += 1;
			}
			j++;
		}
		putchar(format[i]);
		i++;
	}
	va_end(arguments);
	return (i);
}
