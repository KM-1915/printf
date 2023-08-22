#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
nt _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == '%') {
                putchar('%');
                count++;
            } else if (*format == 'C') {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 'S') {
                char *s = va_arg(args, char*);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '0') {
                putchar('%');
                putchar('0');
                count += 2;
            } else if (*format == 'b') {
                unsigned int num = va_arg(args, unsigned int);
                unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
                while (mask > 0) {
                    putchar((num & mask) ? '1' : '0');
                    mask >>= 1;
                    count++;
                }
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
int printf_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
