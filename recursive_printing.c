#include "holberton.h"

/**
 *rpu - recursive printing int.
 *@x: unsigned int number to print
 *@BASE: base for the printing
 *Return: Number of  printed numbers.
*/
int rpu(int x, int BASE)
{
	char c;
	int i = 0, sign = 0;
	char *ctable = "0123456789ABCDEF";

	if (x < 0)
	{
		sign = 1;
		x = (-1) * x;
		i++;
	}
	if (sign == 1)
		_putchar('-');
	if (x)
	{
		c = ctable[x % BASE];
		i++;
		i += rpu(x / BASE, BASE);
		_putchar(c);
	}
	return (i);
}

/**
 *rpuu - recursive printing unsigned hexadecimal.
 *@x: unsigned int number to print
 *@BASE: base for the printing
 *@flag: flag to print hexas in uppercase or not
 *Return: Number of  printed numbers.
*/
int rpuu(unsigned int x, int BASE, int flag)
{
	char c;
	int i = 0;
	char *ctable;
	char y[] = "0123456789abcdef";
	char z[] = "0123456789ABCDEF";

	if (flag == 0)
		ctable = y;
	else if (flag == 1)
		ctable = z;


	if (x)
	{
		c = ctable[x % BASE];
		i++;
		i += rpu(x / BASE, BASE);
		_putchar(c);
	}
	return (i);
}


/**
 *rpup - recursive printing adress.
 *@x: unsigned int number to print
 *@BASE: base for the printing
 *Return: Number of  printed numbers.
*/
int rpup(unsigned long int x, int BASE)
{
	char c;
	int i = 0;
	char *ctable = "0123456789abcdef";

	if (x)
	{
		c = ctable[x % BASE];
		i++;
		i += rpup(x / BASE, BASE);
		_putchar(c);
	}
	return (i);
}

int printr(va_list arguments)
{
	int i = 0;
	char *string = va_arg(arguments, char *);

	if (string == NULL)
	{
		write(1,"(null)", 6);
		return (6);
	}
	i += ( rpr(string));
	return (i);
}

int rpr(char *string)
{
	int i = 0;
	if(*string == '\0')
	{;
		return(i);
	}

	string++;
	i += (rpr(string));
	string--;
	_putchar(*string);
	i++;

	return(i);

}

