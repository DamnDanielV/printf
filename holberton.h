#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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
int print_char(va_list arguments);
int print_str(va_list arguments);
int print_number(va_list arguments);
int c_n(const char *, int *i, va_list arguments);
int _putchar(char c);
int printd(va_list arguments);
int print_unsigned(va_list arguments);
int printS(va_list arguments);
int printb(va_list arguments);
int print_ocunsi(va_list arguments);
int printhex(va_list arguments);
int printp(va_list arguments);
int rpuu(unsigned int x, int BASE, int flag);
int rpu(int x, int BASE);
int rpup(unsigned long int x, int BASE);
int printHEX(va_list arguments);
int printr(va_list arguments);
int rpr(char *string);
#endif
