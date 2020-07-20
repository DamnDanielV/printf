#include "holberton.h"
/**
 * print_char - print char with write
 * @arguments: char to be print
 *
 * Return: one
 */
int print_char(va_list arguments)
{
	char c;

	c = va_arg(arguments, int);
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
		_putchar(*string);
	return (i);
}
/**
 * print_number - print number
 * @arguments: number to be print
 * Return: number of chars printed
 */
int print_number(va_list arguments)
{
	int aux, size = 1, a, b, pu_ch = 0;
	int n = va_arg(arguments, int);

	b = n % 10;
	n = n / 10;
	aux = n;
	if (b < 0)
	{
		b = -1 * b;
		aux = -1 * aux;
		n = -1 * n;
		_putchar('-');
		pu_ch++;
	}
	if (aux > 0)
	{
		while (aux / 10 != 0)
		{
			aux = aux / 10;
			size = size * 10;
		}
		while (size > 0)
		{
			a = n / size;
			_putchar('0' + a);
			n = n - a * size;
			size = size / 10;
			pu_ch++;
		}
	}
	_putchar('0' + b);
	return (pu_ch);
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
