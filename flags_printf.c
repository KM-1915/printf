#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * _flags - turns flags on
 * @s: char that holds flag
 * @f: pointer to the struct flags to turn flags on
 * Return: 1 correct, 0 otherwise
 */
int _flags(char s, flags_t *f)
{
	int n = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			n = 1;
			break;
		case ' ':
			f->space = 1;
			n = 1;
			break;
		case '#':
			f->hash = 1;
			n = 1;
			break;
		case '0':
			f->zero = 1;
			n = 1;
			break;
		case '-':
			f->minus = 1;
			n = 1;
			break;	
	}
	return (n);
}
