#include"main.h"
#include<stdio.h>
#include<stdlib.h>
/**
 * _putchar - Fuction that prints to the std output
 * @c: char to print
 * Return: the char printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
