#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * _printstr - function that print a string
 * @s: pointer
 * Return: 0
 */
int _printstr(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		n++;
	}
	return (n);
}
