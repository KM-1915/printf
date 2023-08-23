#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * print_num - printing numbers
 * @i: number
 * Return: 0
 */
int print_num(int i)
{
	unsigned int a, b, c, d, e;
	int num = 0;

	if (i < 0)
	{
		_putchar('-');
		i = i * -1;
		num++;
	}
	b = i;
	c = 1;
	for (a = 1 ; b > 9 ; a++)
	{
		b = b / 10;
		c = c * 10;
	}
	for (e = 1; e <= a; e++)
	{
		d = i / c;
		i = i % c;
		c = c / 10;
		_putchar(d + '0');
		num++;
	}
	return (num);
}

/**
 * print_binary - chnages decimals to binary
 * @i: decimal
 * Return: 0
 */
int print_binary(unsigned int i)
{
	unsigned int a, b, c, d, e;
	int num = 0;

	b = i;
	c = 1;
	for (a = 1 ; b > 1 ; a++)
	{
		b = b / 2;
		c = c * 2;
	}
	for (e = 1; e <= a; e++)
	{
		d = i / c;
		i = i % c;
		c = c / 2;
		_putchar(d + '0');
		num++;
	}
	return (num);
}
