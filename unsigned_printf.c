#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * print_uns - print unsigned numbers
 * @i: number to print
 * Return: 0
 */
int print_uns(unsigned int i)
{
	int num = 0;
	unsigned int num_copy = i;

	if (i == 0)
		num = 1;
	while (num_copy != 0)
	{
		num_copy = num_copy / 10;
		num++;
	}
	if (i >= 10)
		print_uns(i / 10);
	_putchar (i % 10 + '0');
	return (num);
}
/**
 * print_oct - print numbers in base 8
 * @i: number to print
 * Return: 0
 */
int print_oct(unsigned int i)
{
	unsigned int a, b, c, d, e;
	int num = 0;

	b = i;
	c = 1;
	for (a = 1 ; b > 7 ; a++)
	{
		b = b / 8;
		c = c * 8;
		num++;
	}
	for (e = 1; e <= a; e++)
	{
		d = i / c;
		i = i % c;
		c = c / 8;
		_putchar(d + '0');
		num++;
	}
	return (num);
}
