#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
unsigned char for_flags(const char *flag, char *ind);
unsigned char for_length(const char *mod, char *ind);
int _width(va_list arg, const char *mod, char *ind);
int _precision(va_list arg, const char *mod, char *ind);
unsigned int (*for_specifiers(const char *spec))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/**
 * for_flags - for flags
 * @flag: pointer
 * @ind: index
 * Return: 0
 */
unsigned char for_flags(const char *flag, char *ind)
{
	int n, m;
	unsigned char r = 0;
	flag_t flags[] = {
		{' ', SPACE},
		{'+', PLUS},
		{'#', HASH},
		{'-', MINUS},
		{'0', ZERO},
		{0, 0}
	};

	for (n = 0; flag[n]; n++)
	{
		for (m = 0; flags[m].flag != 0; m++)
		{
			if (flag[n] == flags[m].flag)
			{
				(*ind)++;
				if (r == 0)
					r = flags[m].value;
				else
					r |= flags[m].value;
				break;
			}
		}
		if (flags[m].value == 0)
			break;
	}
	return (r);
}

/**
 * for_length - for length
 * @mod: pointer
 * @ind: ind
 * Return: 0
 */
unsigned char for_length(const char *mod, char *ind)
{
	if (*mod == 'h')
	{
		(*ind)++;
		return (SHORT);
	}

	else if (*mod == 'l')
	{
		(*ind)++;
		return (LONG);
	}
	return (0);
}

/**
 * _width - for width
 * @arg: arguments
 * @mod: pointer
 * @ind: index
 * Return: 0
 */
int _width(va_list arg, const char *mod, char *ind)
{
	int value = 0;

	while ((*mod >= '0' && *mod <= '9') || (*mod == '*'))
	{
		(*ind)++;

		if (*mod == '*')
		{
			value = va_arg(arg, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*mod - '0');
		mod++;
	}

	return (value);
}

/**
 * _precision - for preciison
 * @arg: arguments
 * @mod: pointer
 * @ind: index
 * Return: 0
 */
int _precision(va_list arg, const char *mod, char *ind)
{
	int value = 0;

	if (*mod != '.')
		return (-1);

	mod++;
	(*ind)++;

	if ((*mod <= '0' || *mod > '9') &&
	     *mod != '*')
	{
		if (*mod == '0')
			(*ind++;
		return (0);
	}

	while ((*mod >= '0' && *mod <= '9') ||
	       (*mod == '*'))
	{
		(*ind)++;

		if (*mod == '*')
		{
			value = va_arg(arg, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*mod - '0');
		mod++;
	}
	return (value);
}

/**
 * *for_specifiers - specifier conversion
 * @spec: pointer
 * Return: 0
 * Description: for non-cutom and custom specifiers
 */
unsigned int (*for_specifiers(const char *spec))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int n;
	converter_t converters[] = {
		{'c', for_c},
		{'s', for_s},
		{'d', for_di},
		{'i', for_di},
		{'%', for_percent},
		{'b', for_b},
		{'u', for_u},
		{'o', for_o},
		{'x', for_x},
		{'X', for_X},
		{'S', for_S},
		{'p', for_p},
		{'r', for_r},
		{'R', for_R},
		{0, NULL}
	};

	for (n = 0; converters[n].func; n++)
	{
		if (converters[n].specifier == *spec)
			return (converters[n].func);
	}

	return (NULL);
}
