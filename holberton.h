#ifndef _HOLBERTON_
#define _HOLBERTON_
#include <stdarg.h>
#include<stdio.h>
/**
 * struct struct_specifier - struct to functions print
 * @c: specifier
 * @func: pointer to the specifier function
 */
typedef struct struct_specifier
{
	char c;
	void (*func)(va_list);
} str_speci;

int _putchar(char c);
int _printf(const char *format, ...);
void print_string(va_list arguments);
void print_char(va_list arguments);
void print_percent(va_list arguments);
void print_integer(va_list arguments);

#endif
