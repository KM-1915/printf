#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int custom_printf(const char *format, ...);

#endif // MAIN_H

/*width*/
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

void handleFieldWidth(int intValue, float floatValue, char charValue);

#endif // MAIN_H

/*precision*/
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

// Custom function to handle precision for non-custom conversion specifiers
void custom_printf(const char *format, ...);

/*0 flag */
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

// Custom printf function with '0' flag support
void custom_printf(const char *format, ...);

/*- flag*/
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

// Function declarations
void printDefaultFormatting(int num, float floatNum, char character);
void printLeftJustifiedFormatting(int num, float floatNum, char character);

/*flag r1*/
#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void reverseString(char *str);

int customPrintf(const char *format, ...);
void rot13String(char *str);
int customPrintf(const char *format, ...);

int _putchar(char c);
int printf_HEX(va_list val);
int printf_np_string(va_list val);
int printf_hexidec(unsigned long int num);
int _printf(const char *format, ...);
int percentage_sign(void);
int printf_string(va_list val);
int printf_char(va_list val);
void print_buffer (char buffer[], int *buff_ind);
int printf_hex(va_list val);
int printf_unsigned(va_list args);
int printf_oct(va_list val);
int printf_pointer(va_list val);
int printf_int(va_list args);
int printf_dec(va_list args);

#endif
