#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args, char *buffer, int *index);
int print_string(va_list args, char *buffer, int *index);
int (*get_op_func(const char *format))(va_list, char *, int *);

/**
 * struct print - struct
 * @type: type of argument
 * @f: function to print
 */
typedef struct print
{
char *type;
int (*f)(va_list, char *, int *);
} print_t;

#endif
