#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>

#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define MINUS 16
#define FLAG_PLUS (flags & 1)
#define FLAG_SPACE ((flags >> 1) & 1)
#define FLAG_HASH ((flags >> 2) & 1)
#define FLAG_ZERO ((flags >> 3) & 1)
#define FLAG_MINUS ((flags >> 4) & 1)

#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - for buffers
 * @buffer: buffer pointer
 * @start: start pointer
 * @len: length
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - for converters
 * @spec for specifiers
 * @func: pointer
 */
typedef struct converter_s
{
	unsigned char spec;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;
/**
 * struct flag_s - for flags
 * @flag: flag char
 * @value: int value
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);
int for_printf(const char *format, va_list arg, buffer_t *output);
void sort(va_list arg, buffer_t *output);

unsigned int base_s(buffer_t *output, long int num, char *base,
                unsigned char flags, int width, int precision);
unsigned int base_u(buffer_t *output,
                unsigned long int num, char *base,
                unsigned char flags, int width, int precision);

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int i);
void free_buffer(buffer_t *output);
buffer_t *_buffer(void);

unsigned char for_flags(const char *flag, char *ind);
unsigned char for_length(const char *mod, char *ind);
int _width(va_list arg, const char *mod, char *ind);
int _precision(va_list arg, const char *mod, char *ind);
unsigned int (*for_specifiers(const char *spec))(va_list, buffer_t *,
                unsigned char, int, int, unsigned char);


unsigned int for_di(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_b(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_u(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_o(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);


unsigned int for_x(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_X(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);

unsigned int for_s(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_S(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_r(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_R(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);


unsigned int for_width(buffer_t *output, unsigned int print,
                unsigned char flags, int width);
unsigned int string_width(buffer_t *output,
                unsigned char flags, int width, int precision, int size);
unsigned int neg_width(buffer_t *output, unsigned int print,
                unsigned char flags, int width);

unsigned int for_c(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_percent(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
unsigned int for_p(va_list arg, buffer_t *output,
                unsigned char flags, int width, int precision, unsigned char len);
#endif
