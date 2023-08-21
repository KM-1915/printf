#include "main.h"
#include<stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: a character string
 * Return: number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	int c, num = 0;
	char *s;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				num++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				num++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char*);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					num++;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (num);
}
