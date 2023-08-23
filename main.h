#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_hex(unsigned int i);
int print_Hex(unsigned int i);
int print_binary(unsigned int i);
int print_unsigned(unsigned int i);
int _puts(char *str);
int print_num(int i);
int _form1(char c, int num, va_list arg);
int _form2(char c, int num, va_list arg);
int _form3(char c, int num, va_list arg);
int _form4(char c, int num, va_list arg);
int print_rev(char *str);
int _printstr(char *s);
int rot13(char *s);
int print_int(uintptr_t i);
/**
 * struct flags - struct containing flags to turn on.
 * @plus: flag for '+' char
 * @space: flag for ' ' char
 * @hash: flag for '#' char
 * @minus: flag for '-' char
 * @zero: flag for '0' char
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int minus;
	int zero;

int _flags(char s, flags_t *f);
} flags_t;

#endif
