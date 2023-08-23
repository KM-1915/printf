#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
int is_digit(char);
/**
 * _width: for width calculation
 * @format: character of strings
 * @n: printed args
 * @arg: arguments
 * Return: 0
 */
int _width(const char *format, int *n, va_list arg)
{
	int ind;
	int width = 0;

	for (ind = *n + 1; format[ind] != '\0'; ind++)
	{
		if (is_digit(format[ind]))
		{
			width *= 10;
			width += format[ind] - '0';
		}
		else if (format[ind] == '*')
		{
			ind++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}
	*n = ind - 1;
	return (width);
}
/**
 * _precision - precision calculation
 * @format: a character of strings
 * @n: arguments
 * @arg: arguments
 * Return: 0
 */
int _precision(const char *format, int *n, va_list arg)
{
	int ind = *n + 1;
	int precision = -1;

	if (format[ind] != '.')
		return (precision);

	precision = 0;

	for (ind += 1; format[ind] != '\0'; ind++)
	{
		if (is_digit(format[ind]))
		{
			precision *= 10;
			precision += format[ind] - '0';
		}
		else if (format[ind] == '*')
		{
			ind++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
	}
	*n = ind - 1;
	return (precision);
}
