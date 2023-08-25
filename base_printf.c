#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * base_s - from int to base
 * @output: output
 * @num: int
 * @base: pointer
 * @flags: for flags
 * @width: for width
 * @precision: for precision
 * Return: bytes in buffer
 */
unsigned int base_s(buffer_t *output, long int num, char *base,
		unsigned char flags, int width, int precision)
{
	int size;
	char dig, fig = '0';
	unsigned int r = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		r += base_s(output, num / size, base,
				flags, width - 1, precision - 1);

	else
	{
		for (; precision > 1; precision--, width--)
			r += _memcpy(output, &fig, 1);

		if (FLAG_MINUS == 0)
		{
			fig = (FLAG_ZERO == 1) ? '0' : ' ';
			for (; width > 1; width--)
				r += _memcpy(output, &fig, 1);
		}
	}

	dig = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &dig, 1);

	return (r);
}

/**
 * base_u - from int to base
 * @output: output
 * @num: int
 * @base: pointer
 * @flags: flag pointer
 * @width: width
 * @precision: precision
 * Return: 0
 */
unsigned int base_u(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int width, int precision)
{
	unsigned int size, r = 1;
	char dig, fig = '0', *ld = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		r += base_u(output, num / size, base,
				flags, width - 1, precision - 1);

	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			width -= 2;
			precision -= 2;
		}
		for (; precision > 1; precision--, width--)
			r += _memcpy(output, &fig, 1);

		if (FLAG_MINUS == 0)
		{
			fig = (FLAG_ZERO == 1) ? '0' : ' ';
			for (; width > 1; width--)
				r += _memcpy(output, &fig, 1);
		}
		if (((flags >> 5) & 1) == 1)
			r += _memcpy(output, ld, 2);
	}

	dig = base[(num % size)];
	_memcpy(output, &dig, 1);

	return (r);
}
