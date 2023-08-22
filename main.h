#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int custom_printf(const char *format, ...);
void handleFieldWidth(int intValue, float floatValue, char charValue);
void printDefaultFormatting(int num, float floatNum, char character);
void printLeftJustifiedFormatting(int num, float floatNum, char character);

void reverseString(char *str);
void rot13String(char *str);

int _putchar(char c);
int printf_HEX(va_list val);
int printf_np_string(va_list val);
int printf_hexidec(unsigned long int num);
int _printf(const char *format, ...);
int percentage_sign(void);
int printf_string(va_list val);
int printf_char(va_list val);
void print_buffer(char buffer[], int *buff_ind);
int printf_hex(va_list val);
int printf_unsigned(va_list args);
int printf_oct(va_list val);
int printf_pointer(va_list val);
int printf_int(va_list args);
int printf_dec(va_list args);
int (*get_op_func(const char *format))(va_list, char *, int *);
int print_string(va_list args, char *buffer, int *index);
int print_char(va_list args, char *buffer, int *index);
int printf_bin(va_list val);

#endif
