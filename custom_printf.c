#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 *print_rev - print string in reverse
 *@str: string pointer
 *Return: 0
 */
int print_rev(char *str)
{
	char *z = str;
	int n;
	int num1 = 0;
	int num = 0;

	while (*str != '\0')
	{
		str++;
		num1++;
	}

	n = num1 - 1;
	while (n >= 0)
	{
		_putchar(*(z + n));
		n--;
		num++;
	}

	return (num);
}
/**
 * rot13 - encoding to ROT13
 * @s: string
 * Return: 0
 */
int rot13(char *s)
{
	int a, b, num = 0;
	char first[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char second[52] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	a = 0;
	while (s[a] != 0)
	{
		if ((s[a] >= 'A' && s[a] <= 'Z') || (s[a] >= 'a' && s[a] <= 'z'))
		{
			for (b = 0; b < 52; b++)
			{
				if (s[a] == first[b])
				{
					num += _putchar(second[b]);
				}
			}
		}
		else
			num += _putchar(s[a]);
		a++;
	}
	return (num);
}
