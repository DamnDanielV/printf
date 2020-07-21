#include "holberton.h"

/**
 * print_number - print number
 * @arguments: number to be print
 * Return: number of chars printed
 */
int print_number(va_list arguments)
{
	int aux, size = 1, a, b, pu_ch = 1;
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
 *printu- prints signed int
 *@arguments: a struct of vargs to print
 *
 *Return: int with the numbers of characters printed.
 */
int printd(va_list arguments)
{
	int i;
	 int x = va_arg(arguments, int);

	 i = (x == 0) ? _putchar('0') : rpu(x, 10);
	return (i);
}
/**
 *printb- prints octal int
 *@arguments: a struct of vargs to print
 *
 *Return: int with the numbers of characters printed.
 */
int printb(va_list arguments)
{
	int i;
	 unsigned int x = va_arg(arguments, unsigned int);

	 i = (x == 0) ? _putchar('0') : rpu(x, 2);
	return (i);
}

int printhex(va_list arguments)
{
	 int i;
	 unsigned int x = va_arg(arguments, unsigned int);
 
	 i = (x == 0) ? _putchar('0') : rpuu(x, 16, 0);
	 return (i);

}

int printHEX(va_list arguments)
{
	 int i = 0;
	 unsigned int x = va_arg(arguments, unsigned int);
 
	 i = (x == 0) ? _putchar('0') : rpuu(x, 16, 1);
	 return (i);

}

int printp(va_list arguments)
{
	int i = 0;
	unsigned long int addr = va_arg(arguments, unsigned long int);
	_putchar('0');
	_putchar('x');
	i += (addr == 0) ? _putchar('0') : rpup(addr,16);
        return (i);
	
/*	unsigned long int addr[16], recv;
	int aux = 0, i = 0;

	recv = va_arg(arguments, unsigned long int);
	if (recv == 0)
	{
		_putchar('0');
	}
	else
	{
		addr[0] = _putchar('0');
		addr[1] = _putchar('x');
		while (addr[i] != '\0')
		{
			addr[i] = recv % 16;
			addr /= 16;
			}*/

}

/**
 *rpu - recursive printing int.
 *@x: unsigned int number to print
 *
q *Return: Number of  printed numbers.
 */
int  rpu(int x, int BASE)
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
 *rpuu - recursive printing unsigned int.
 *@x: unsigned int number to print
 *
q *Return: Number of  printed numbers.
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
	else
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
