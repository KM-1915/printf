#include <stdio.h>
#include <stdarg.h>

int custom_printf(const char *format, ...);

int main() {
    int a = 42;
    long b = 1234567890L;
    unsigned int c = 98765;
    short d = 1234;
    
    custom_printf("Int (decimal): %d\n", a);
    custom_printf("Long (decimal): %ld\n", b);
    custom_printf("Unsigned Int (decimal): %u\n", c);
    custom_printf("Short (decimal): %hd\n", d);
    
    custom_printf("Int (octal): %o\n", a);
    custom_printf("Long (octal): %lo\n", b);
    custom_printf("Unsigned Int (octal): %o\n", c);
    custom_printf("Short (octal): %ho\n", d);
    
    custom_printf("Int (hexadecimal): %x\n", a);
    custom_printf("Long (hexadecimal): %lx\n", b);
    custom_printf("Unsigned Int (hexadecimal): %x\n", c);
    custom_printf("Short (hexadecimal): %hx\n", d);
    
    return 0;
}

int custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;
    char ch;
    for (int i = 0; (ch = format[i]) != '\0'; ++i) {
        if (ch == '%') {
            ++i;
            if (format[i] == 'l') {
                ++i;
                if (format[i] == 'd' || format[i] == 'i') {
                    long num = va_arg(args, long);
                    count += printf("%ld", num);
                } else if (format[i] == 'u') {
                    unsigned long num = va_arg(args, unsigned long);
                    count += printf("%lu", num);
                } else if (format[i] == 'o') {
                    unsigned long num = va_arg(args, unsigned long);
                    count += printf("%lo", num);
                } else if (format[i] == 'x' || format[i] == 'X') {
                    unsigned long num = va_arg(args, unsigned long);
                    count += printf(format[i] == 'x' ? "%lx" : "%lX", num);
                } else {
                    putchar('%');
                    putchar('l');
                    putchar(format[i]);
                    count += 3;
                }
            } else if (format[i] == 'h') {
                ++i;
                if (format[i] == 'd' || format[i] == 'i') {
                    short num = va_arg(args, int); // Short is promoted to int
                    count += printf("%hd", num);
                } else if (format[i] == 'u') {
                    unsigned short num = va_arg(args, int); // Short is promoted to int
                    count += printf("%hu", num);
                } else if (format[i] == 'o') {
                    unsigned short num = va_arg(args, int); // Short is promoted to int
                    count += printf("%ho", num);
                } else if (format[i] == 'x' || format[i] == 'X') {
                    unsigned short num = va_arg(args, int); // Short is promoted to int
                    count += printf(format[i] == 'x' ? "%hx" : "%hX", num);
                } else {
                    putchar('%');
                    putchar('h');
                    putchar(format[i]);
                    count += 3;
                }
            } else {
                putchar('%');
                putchar(format[i]);
                count += 2;
            }
        } else {
            putchar(ch);
            ++count;
        }
    }
    
    va_end(args);
    return count;
}

/*width*/
#include "main.h"

int main() {
    int intValue = 12345;
    float floatValue = 3.14159;
    char charValue = 'A';
    
    handleFieldWidth(intValue, floatValue, charValue);
    
    return 0;
}

void handleFieldWidth(int intValue, float floatValue, char charValue) {
    // Handling field width for integer value
    printf("Integer with width 10: |%10d|\n", intValue);
    printf("Integer with width 5:  |%5d|\n", intValue);
    
    // Handling field width for floating-point value
    printf("Float with width 10:   |%10f|\n", floatValue);
    printf("Float with width 7:    |%7f|\n", floatValue);
    
    // Handling field width for character value
    printf("Char with width 5:     |%5c|\n", charValue);
}
/*precision*/
#include <stdio.h>
#include <stdarg.h>

// Custom function to handle precision for non-custom conversion specifiers
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        // Normal characters are printed as-is
        if (*format != '%') {
            putchar(*format);
            format++;
            continue;
        }

        // Handle format specifiers
        format++;

        // Check for precision
        int precision = -1; // Initialize precision to -1 (no precision specified)
        if (*format == '.') {
            format++; // Move past the '.'
            precision = 0; // Initialize precision to 0
            
            // Parse precision value
            while (*format >= '0' && *format <= '9') {
                precision = precision * 10 + (*format - '0');
                format++;
            }
        }

        // Process conversion specifiers
        switch (*format) {
            case 'd':
            case 'i': {
                int num = va_arg(args, int);
                if (precision == -1) {
                    printf("%d", num);
                } else {
                    printf("%0*d", precision, num);
                }
                break;
            }
            case 'f': {
                double num = va_arg(args, double);
                if (precision == -1) {
                    printf("%f", num);
                } else {
                    printf("%.*f", precision, num);
                }
                break;
            }
            // Add more cases for other conversion specifiers as needed
            default:
                putchar('%');
                putchar(*format);
                break;
        }

        format++;
    }

    va_end(args);
}

int main() {
    custom_printf("Integer: %.5d\n", 123);
    custom_printf("Float: %.2f\n", 3.14159);

    return 0;
}
