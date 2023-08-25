#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * for_x - for unsigned int to hexadecimal l/c
 * @arg: argument
 * @flags: for flas
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: 0
 */
unsigned int for_x(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	unsigned long int num;
	unsigned int r = 0;
	char *ld = "0x";

	if (len == LONG)
		num = va_arg(arg, unsigned long int);
	else
		num = va_arg(arg, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (FLAG_HASH == 1 && num != 0)
		r += _memcpy(output, ld, 2);

	if (!(num == 0 && precision == 0))
		r += base_u(output, num, "0123456789abcdef",
				flags, width, precision);

	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_X - for unsigned int to hexadecimal in u/c
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for legnth
 * @output: output
 * Return:0
 */
unsigned int for_X(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	unsigned long int num;
	unsigned int r = 0;
	char *ld = "0X";

	if (len == LONG)
		num = va_arg(arg, unsigned long);
	else
		num = va_arg(arg, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (FLAG_HASH == 1 && num != 0)
		r += _memcpy(output, ld, 2);

	if (!(num == 0 && precision == 0))
		r += base_u(output, num, "0123456789ABCDEF",
				flags, width, precision);

	r += neg_width(output, r, flags, width);

	return (r);
}
