#include"main.h"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * _memcpy - copies bytes from memory
 * @output: output
 * @src: source pointer
 * @i: number
 * Return: 0
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int i)
{
	unsigned int ind;

	for (ind = 0; ind < i; ind++)
	{
		*(output->buffer) = *(src + ind);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}

		else
			(output->buffer)++;
	}
	return (i);
}

/**
 * free_buffer - frees buffer
 * @output: output
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * _buffer - for buffer
 * Return: 0
 */
buffer_t *_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->buffer;
	output->len = 0;

	return (output);
}
