#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct struct_specifier - struct to functions print
 * @ch: specifier
 * @fu_pr: pointer to the specifier function
 */
typedef struct struct_specifier
{
	char ch;
	int (*fu_pr)(va_list);
} str_speci;

int _printf(const char *format, ...);
int (*match_parameter(char s))(va_list);
int print_char(va_list vl);
int print_str(va_list vl);
int print_number(va_list vl);
int c_n(char);
int _putchar(char c);

#endif
