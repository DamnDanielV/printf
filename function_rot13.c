#include "holberton.h"

/**
 * printR - function that encodes a string into 1337.
 *@arguments: (va_list arguments): the string to encode
 *Return: pointer to the encoded array
 */
int printR(va_list arguments)
{
	int i, j, z = 0;
	char c[] = {"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"};
	char num[] = {"nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmMnN"};
	char *s = va_arg(arguments, char *);

	if (s == NULL)
	{
		write(1, NULL, 6);
		return (6);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		j = 0;
		while (c[j] != '\0')
		{
			if (s[i] == c[j])
			{
				_putchar(num[j]);
				z++;
				break;
			}
			j++;
		}
	}
	return (z);
}
