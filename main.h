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

