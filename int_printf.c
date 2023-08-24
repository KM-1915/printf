#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
unsigned int for_di(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_b(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_u(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_o(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);

/**
 * for_di - for signed int
 * @arg: argument
 * @flags: For flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: 0
 */
unsigned int for_di(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	long int d, copy;
	unsigned int r = 0, count = 0;
	char fig, space = ' ', minus = '-', plus = '+';

	if (len == LONG)
		d = va_arg(arg, long int);
	else
		d = va_arg(arg, int);
	if (len == SHORT)
		d = (short)d;

	if (FLAG_SPACE == 1 && d >= 0)
		ret += _memcpy(output, &space, 1);

	if (precision <= 0 && FLAG_MINUS == 0)
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (FLAG_PLUS == 1 && d >= 0) ? 1 : 0;
		count += (FLAG_SPACE == 1 && d >= 0) ? 1 : 0;

		if (FLAG_ZERO == 1 && FLAG_PLUS == 1 && d >= 0)
			r += _memcpy(output, &plus, 1);

		if (FLAG_ZERO == 1 && d < 0)
			r += _memcpy(output, &neg, 1);

		fig = (FLAG_ZERO == 1) ? '0' : ' ';
		for (width -= count; width > 0; width--)
			r += _memcpy(output, &fig, 1);
	}

	if (FLAG_ZERO == 0 && d < 0)
		r += _memcpy(output, &minus, 1);
	if (FLAG_ZERO == 0 && (FLAG_PLUS == 1 && d >= 0))
		r += _memcpy(output, &plus, 1);

	if (!(d == 0 && precision == 0))
		r += base_s(output, d, "0123456789",
				flags, 0, precision);

	r += neg_width(output, ret, flags, width);

	return (r);
}

/**
 * for_b - for unsigned int to binary
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for legnth
 * @output: output
 * Return: on success
 */
unsigned int for_b(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	unsigned int num;

	num = va_arg(arg, unsigned int);

	(void)len;

	return (base_u(output, num, "01", flags, width, precision));
}

/**
 * for_o - for unsigned int to octal
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: precision
 * @len: for length
 * @output: output
 * Return: 0
 */
unsigned int for_o(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	unsigned long int num;
	unsigned int r = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(arg, unsigned long int);
	else
		num = va_arg(args unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (FLAG_HASH == 1 && num != 0)
		r += _memcpy(output, &zero, 1);

	if (!(num == 0 && precision == 0))
		r += base_u(output, num, "01234567",
				flags, width, precision);

	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_u - for unsigned int to decimal
 * @arg: arguments
 * @flags: Flag modifiers.
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: 0
 */
unsigned int for_u(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	unsigned long int num;
	unsigned int r = 0;

	if (len == LONG)
		num = va_arg(arg, unsigned long int);
	else
		num = va_arg(arg, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && precision == 0))
		r += base_u(output, num, "0123456789",
				flags, width, precision);

	r += neg_width(output, r, flags, width);

	return (r);
}
