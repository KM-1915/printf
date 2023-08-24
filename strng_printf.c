#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
unsigned int for_s(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_S(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_r(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_R(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len);

/**
 * for_s: from argument to string
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Description: for strings
 * Return: 0
 */
unsigned int for_s(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int r = 0;

	(void)flags;
	(void)len;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	r += string_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	while (*str != '\0' && precision > 0)
	{
		r += _memcpy(output, str, 1);
		precision--;
		str++;
	}

	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_S - from argument to string
 * @arg: arguments
 * @flags: for flag
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 * are stored as \x followed by the ASCII code value in hexadec
 * Return: 0
 */
unsigned int for_S(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)", *hexa = "\\x", zero = '0';
	int size, ind;
	unsigned int r = 0;

	(void)len;
	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	r += string_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	for (ind = 0; *(str + ind) != '\0' && ind < precision; ind++)
	{
		if (*(str + ind) < 32 || *(str + ind) >= 127)
		{
			r += _memcpy(output, hexa, 2);
			if (*(str + ind) < 16)
				r += _memcpy(output, &zero, 1);
			r += base_u(output, *(str + ind),
					     "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		r += _memcpy(output, (str + ind), 1);
	}

	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_r - for reversing a string
 * @arg: arguments
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: bytes in buffer
 */
unsigned int for_r(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, n;
	unsigned int r = 0;

	(void)flags;
	(void)len;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	r += string_width(output, flags, width, precision, size);

	end = size - 1;
	precision = (precision == -1) ? size : precision;
	for (n = 0; end >= 0 && n < precision; n++)
	{
		r += _memcpy(output, (str + end), 1);
		end--;
	}

	r += neg_width(output, r, flags, width);

	return (r);
}

/**
 * for_R - from string to ROT13
 * @arg: argument
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @len: for length
 * @output: output
 * Return: bytes to buffer
 */
unsigned int for_R(va_list arg, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int n, m, size;
	unsigned int r = 0;

	(void)flags;
	(void)len;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	r += string_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	for (n = 0; *(str + n) != '\0' && n < precision; n++)
	{
		for (m = 0; m < 52; m++)
		{
			if (*(str + n) == *(alpha + m))
			{
				r += _memcpy(output, (rot13 + m), 1);
				break;
			}
		}
		if (m == 52)
			r += _memcpy(output, (str + n), 1);
	}

	r += neg_width(output, r, flags, width);

	return (r);
}
