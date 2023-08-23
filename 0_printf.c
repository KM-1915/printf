#include"main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _form4 - prints depending the format
 * @c: the format sent by the main
 * @num:  for characters printed
 * @arg: arguments
 * Return: 0
 */
int _form4(char c, int num, va_list arg)
{
	intptr_t p;
	void *pi;

	switch (c)
	{
	case 'p':
		pi = va_arg(arg, void *);
		p = (intptr_t)pi;
		if (pi == NULL)
		{
			_printf("(nil)");
			num += 5;
		}
		else
		{
			_putchar('0');
			_putchar('x');
			num += 2;
			num += print_hex(p);
		}
		break;
	default:
		num += 2;
		_putchar('%');
		_putchar(c);
	}
	return (num);
}

/**
 * _form3 - prints depending the format
 * @c: the format sent by the main
 * @num: chars printed
 * @arg: argument
 * Return: 0
 */
int _form3(char c, int num, va_list arg)
{
	char *s;
	int n;
	char si[6] = "(null)";

	switch (c)
	{
	case 'R':
		s = va_arg(arg, char *);
		if (!s)
		{
			for (n = 0; si[n]; n++, num++)
				_putchar(si[n]);
		}
		else
			num += rot13(s);
		break;
	case 'r':
		s = va_arg(arg, char *);
		if (!s)
		{
			for (n = 0; si[n]; n++, num++)
				_putchar(si[n]);
		}
		else
			num += print_rev(s);
		break;
		default:
			num = _form4(c, num, arg);
	}
	return (num);
}
/**
 * _form2 - prints depending the format
 * @c: the format sent by the main
 * @num: chars printed
 * @arg: argument
 * Return: 0
 */
int _form2(char c, int num, va_list arg)
{
	unsigned int k;

	switch (c)
	{
		case 'b':
			k = va_arg(arg, unsigned int);

			num += print_binary(k);
			break;
		case 'o':
			k = va_arg(arg, unsigned int);

			num += print_int(k);
			break;
		case 'x':
			k = va_arg(arg, unsigned int);

			num += print_hex(k);
			break;
		case 'X':
			k = va_arg(arg, unsigned int);

			num += print_Hex(k);
			break;
		case 'u':
			k = va_arg(arg, unsigned int);

			num += print_unsigned(k);
			break;
		default:
			num = _form3(c, num, arg);
	}
	return (num);
}

/**
 * _form - prints depending the format
 * @c: the format sent by the main
 * @num: chars printed
 * @arg: arguments
 * Return: @count the number of characters printed
 */
int _form(char c, int num, va_list arg)
{
	int n, x;
	char *s;
	char si[6] = "(null)";

	switch (c)
	{
		case 'c':
			x = va_arg(arg, int);
			num += _putchar(x);
			break;
		case 's':
			s = va_arg(arg, char *);
			if (!s)
			{
				for (n = 0; si[n]; n++, num++)
					_putchar(si[n]);
			}
			else
				num += _printstr(s);
			break;
		case '%':
			num += _putchar('%');
			break;
		case 'i':
		case 'd':
			x = va_arg(arg, int);

			if (!x)
			{
				num++;
				_putchar('0');
			} else
				num += print_num(x);
			break;
		default:
			num = _form2(c, num, arg);
	}
	return (num);
}

/**
 * _printf - Fuction that prints to the std output
 * @format: list of parameters passed
 * Return: @count the number of characters printed
 */
int _printf(const char *format, ...)
{
	int n = 0;
	int num = 0;
	va_list arg;

	va_start(arg, format);

	if (!format)
		return (-1);
	for (n = 0; format[n]; n++)
	{
		if (format[n] != '%')
		{
			num++;
			_putchar(format[n]);
		}
		else if (format[n + 1])
		{
			n++;
			num = _form(format[n], num, arg);
		}
		else
			return (-1);
	}
	va_end(arg);
	return (num);
}
