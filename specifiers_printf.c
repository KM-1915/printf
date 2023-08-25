#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * for_c - from arguments to unsigned char
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: bytes to buffer
 */
unsigned int for_c(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char c;
	unsigned int r = 0;

	(void)precision;
	(void)len;

	c = va_arg(arg, int);

	r += for_width(output, r, flags, width);
	r += _memcpy(output, &c, 1);
	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_percent - for percent sign to be stored in buffer
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: bytes to buffer
 */
unsigned int for_percent(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char percent = '%';
	unsigned int r = 0;

	(void)arg;
	(void)precision;
	(void)len;

	r += for_width(output, r, flags, width);
	r += _memcpy(output, &percent, 1);
	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_p - for address arguemnt to hexadecimal
 * @arg: argumnets
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for lenght
 * @output: output
 * Return: bytes to buffer
 */
unsigned int for_p(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int r = 0;

	(void)len;

	address = va_arg(arg, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;
	r += base_u(output, address, "0123456789abcdef",
			flags, width, precision);
	r += neg_width(output, r, flags, width);

	return (r);
}
