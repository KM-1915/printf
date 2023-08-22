#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
int _printf(const char *format, ...)
{
	int c;
	char *s;
	va_list args;
	unsigned int num, mask;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'C')
			{
				c = va_arg(args, int);
				putchar(c);
                		count++;
			}
			else if (*format == 'S')
			{
				s = va_arg(args, char*);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '0')
			{
				putchar('%');
				putchar('0');
				count += 2;
			}
			else if (*format == 'b')
			{
				num = va_arg(args, unsigned int);
				mask = 1 << (sizeof(unsigned int) * 8 - 1);
				
				while (mask > 0)
				{
					putchar((num & mask) ? '1' : '0');
					mask >>= 1;
					count++;
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
	return (count);
}