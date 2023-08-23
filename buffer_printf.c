#include"main.h"
#include<stdarg.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * _putchar - prints to the std output
 * @c: The character to print
 * Return: 1, on error, -1
 */
int _putchar(char c)
{
	static char buff[1024];
	static int n;

	if (c == -1 || n >= 1024)
	{
		write(1, &buff, n);
		n = 0;
	}
	if (c != -1)
	{
		buff[n] = c;
		n++;
	}
	return (1);
}

/**
 * _puts - prints a string
 * @str: pointer to the string to print
 * Return: 0
 */
int _puts(char *str)
{
	register int n;

	for (n = 0; str[n] != '\0'; n++)
		_putchar(str[n]);
	return (n);
}
