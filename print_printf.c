#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * for_width - for width modification
 * @print: chars printed to output
 * @flags: for flags
 * @width: for width
 * @output: output
 * Return: bytes to buffer
 */
unsigned int for_width(buffer_t *output, unsigned int print,
		unsigned char flags, int width)
{
	unsigned int r = 0;
	char wid = ' ';

	if (FLAG_MINUS == 0)
	{
		for (width -= print; width > 0;)
			r += _memcpy(output, &wid, 1);
	}

	return (r);
}

/**
 * string_width - for width modification
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * @output: output
 * @size: string size
 * Return: bytes to buffer
 */
unsigned int string_width(buffer_t *output,
		unsigned char flags, int width, int precision, int size)
{
	unsigned int r = 0;
	char wid = ' ';

	if (FLAG_MINUS == 0)
	{
		width -= (precision == -1) ? size : precision;
		for (; width > 0; width--)
			r += _memcpy(output, &wid, 1);
	}

	return (r);
}

/**
 * neg_width - for trailing spaces to buffer
 * @print: bytes stored to output
 * @flags: for flags
 * @width: for width
 * @output: output
 * Return: bytes to buffer
 */
unsigned int neg_width(buffer_t *output, unsigned int print,
		unsigned char flags, int width)
{
	unsigned int r = 0;
	char wid = ' ';

	if (FLAG_MINUS == 1)
	{
		for (width -= print; width > 0; width--)
			r += _memcpy(output, &wid, 1);
	}

	return (r);
}
