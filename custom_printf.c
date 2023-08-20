#include "main.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

/**
 * _putchar - putchar
 * @c: character
 * Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - print char
 * @args: argument
 * @buffer: buffer
 * @index: index
 * Return: 0
 */
int print_char(va_list args, char *buffer, int *index)
{
	char c = va_arg(args, int);

	buffer[*index] = c;
	(*index)++;
	return (1);
}

/**
 * print_string: prints string
 * @args: argument string
 * @buffer: buffer
 * @index: integer index
 * Return: 0
 */
int print_string(va_list args, char *buffer, int *index)
{
	char *str = va_arg(args, char *);
	int i = 0;

	while (str[i] != '\0')
	{
		buffer[*index] = str[i];
		(*index)++;
		i++;
	}
return (i);
}

/**
 * *get_op_func: get op function
 * @format: a character string
 * Return: 0
 */
int (*get_op_func(const char *format))(va_list, char *, int *)
{
	int i = 0;

	print_t print_arr[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	while (print_arr[i].type != NULL)
	{
		if (*(print_arr[i].type) == *format)
		{
			return (print_arr[i].f);
		}
		i++;
	}
return (NULL);
}

/**
 * _printf: produces output according to a format
 * @format: a character string
 * Return: number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, printed_chars = 0;
	char *buffer;
	int (*function)(va_list, char *, int *);

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		return (-1);
	}

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				return (-1);
			}
		function = get_op_func(&format[i + 1]);
		if (function == NULL)
		{
			buffer[j] = format[i];
			j++;
			printed_chars++;
		}
		else
		{
		i++;
		printed_chars += function(args, buffer, &j);
		}
		}
		else
		{
			buffer[j] = format[i];
			j++;
			printed_chars++;
		}
		i++;
	}
	write(1, buffer, j);
	free(buffer);
	va_end(args);
return (printed_chars);
}
