#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * print_int - convert unsigned int in hexadecimal
 *@i: unsigned int
 * Return: numer times print
 */
int print_int(intptr_t i)
{
	intptr_t frac, temp;

	int mor = 1, mor2;
	char hexadec[100];
	int num = 0;

	frac = i;
	while (frac != 0)
	{
		temp = frac % 16;

		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;

		hexadec[mor++] = temp;
		frac = frac / 16;
	}
	for (mor2 = mor - 1 ; mor2 > 0; mor2--, num++)
		_putchar(hexadec[mor2]);

	return (num);
}
