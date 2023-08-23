#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * print_hex - print number in hexadecimal with lc char
 * @i: unsigned int
 * Return: 0
 */
int print_hex(unsigned int i)
{
	int n, x, remainder, num = 0;
	unsigned int num_copy = i;
	char *hexa;

	if (i == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		num++;
	}
	hexadecimal = malloc(count);
	for (n = 0; i != 0; n++)
	{
		remainder = 0;
		remainder = i % 16;
		if (remainder < 10)
		{
			hexa[n] = remainder + '0';
		}
		else
		{
			hexa[n] = remainder + 'W';
		}
		i /= 16;
	}
	for (x = n - 1; x >= 0; x--)
		_putchar(hexa[x]);
	free(hexa);
	return (num);
}
/**
 * print_Hex - Print number in hexadecimal with uppercase char
 * @i: unsigned int
 * Return: 0
 */
int print_Hex(unsigned int i)
{
	int n, x, remainder, num = 0;
	unsigned int num_copy = i;
	char *hexa;

	if (i == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		num++;
	}
	hexa = malloc(num);
	for (n = 0; i != 0; n++)
	{
		remainder = 0;
		remainder = i % 16;
		if (remainder < 10)
		{
			hexa[n] = remainder + '0';
		}
		else
		{
			hexa[n] = remainder + '7';
		}
		i /= 16;
	}
	for (x = n - 1; x >= 0; x--)
		_putchar(hexa[x]);

	free(hexa);
	return (num);
}
