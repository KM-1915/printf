#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
int _printf(const char *format, ...);
int for_printf(const char *format, va_list arg, buffer_t *output);
void sort(va_list arg, buffer_t *output);

/**
 * sort: sorts files
 * @arg: arguments
 * @output: output
 * Description: for _printf function
 * Return: void
 */
void sort(va_list arg, buffer_t *output)
{
	va_end(arg);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * for_printf - checks string for _printf
 * @format: character string to print
 * @output: output
 * @arg: arguments
 * Return: 0
 */
int for_printf(const char *format, va_list arg, buffer_t *output)
{
	int n, width, precision, r = 0;
	char temp;
	unsigned char flags, len;
	unsigned int (*y)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (n = 0; *(format + n); n++)
	{
		len = 0;
		if (*(format + n) == '%')
		{
			temp = 0;
			flags = for_flags(format + n + 1, &temp);
			width = _width(args, format + n + temp + 1, &temp);
			precision = _precision(arg, format + n + temp + 1,
					&temp);
			len = for_length(format + n + temp + 1, &temp);

			y = for_specifiers(format + n + temp + 1);
			if (y != NULL)
			{
				y += temp + 1;
				r += y(arg, output, flags, width, precision, len);
				continue;
			}
			else if (*(format + n + temp + 1) == '\0')
			{
				r = -1;
				break;
			}
		}
		r += _memcpy(output, (format + n), 1);
		n += (len != 0) ? 1 : 0;
	}
	sort(arg, output);
	return (r);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list arg;
	int r;

	if (format == NULL)
		return (-1);
	output = _buffer();
	if (output == NULL)
		return (-1);

	va_start(arg, format);

	r = for_printf(format, arg, output);

	return (r);
}
