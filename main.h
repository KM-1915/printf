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

#endif // MAIN_H

/*0 flag */
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

// Custom printf function with '0' flag support
void custom_printf(const char *format, ...);

#endif // MAIN_H

/*- flag*/
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

// Function declarations
void printDefaultFormatting(int num, float floatNum, char character);
void printLeftJustifiedFormatting(int num, float floatNum, char character);

#endif /* MAIN_H */

/*flag r1*/
#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void reverseString(char *str);

int customPrintf(const char *format, ...);

#endif // CUSTOM_PRINTF_H
