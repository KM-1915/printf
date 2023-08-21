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

/*0 flag*/
#include <stdio.h>
#include <stdarg.h>

void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            
            // Check for '0' flag character
            int zero_flag = 0;
            if (*format == '0') {
                zero_flag = 1;
                format++;
            }
            
            // Process non-custom conversion specifiers
            switch (*format) {
                case 'd':
                    if (zero_flag) {
                        int width = va_arg(args, int);
                        printf("%0*d", width, va_arg(args, int));
                    } else {
                        printf("%d", va_arg(args, int));
                    }
                    break;
                case 'f':
                    if (zero_flag) {
                        int width = va_arg(args, int);
                        int precision = va_arg(args, int);
                        printf("%0*.*f", width, precision, va_arg(args, double));
                    } else {
                        printf("%f", va_arg(args, double));
                    }
                    break;
                // Add more conversion specifiers as needed
                default:
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        
        format++;
    }

    va_end(args);
}

int main() {
    custom_printf("Normal: %d\n", 42);
    custom_printf("Zero-padded: %0d\n", 5, 42);
    custom_printf("Normal: %f\n", 3.14159);
    custom_printf("Zero-padded: %0f\n", 8, 3, 3.14159);

    return 0;
}

/*- flag*/
#include "main.h"

int main() {
    int num = 12345;
    float floatNum = 123.456;
    char character = 'A';

    printf("Default formatting:\n");
    printDefaultFormatting(num, floatNum, character);

    printf("\nLeft-justified formatting:\n");
    printLeftJustifiedFormatting(num, floatNum, character);

    return 0;
}

void printDefaultFormatting(int num, float floatNum, char character) {
    printf("Integer: %d\n", num);
    printf("Float: %f\n", floatNum);
    printf("Character: %c\n", character);
}

void printLeftJustifiedFormatting(int num, float floatNum, char character) {
    printf("Integer: %-10d|\n", num);
    printf("Float: %-10f|\n", floatNum);
    printf("Character: %-10c|\n", character);
}

/*flag r1*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int customPrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == 'r') {
            i++; // Move past '%'
            char *str = va_arg(args, char *);
            reverseString(str);
            count += printf("%s", str);
        } else {
            count += printf("%c", format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}

int main() {
    char text[] = "Hello, world!";
    char format[] = "Original: %s\nReversed: %r\n";

    customPrintf(format, text, text);
    return 0;
}

/*flag r2*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void rot13String(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if ((c >= 'a' && c <= 'z')) {
            c = 'a' + (c - 'a' + 13) % 26;
        } else if ((c >= 'A' && c <= 'Z')) {
            c = 'A' + (c - 'A' + 13) % 26;
        }

        str[i] = c;
    }
}

int customPrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == 'R') {
            i++; // Move past '%'
            char *str = va_arg(args, char *);
            rot13String(str);
            count += printf("%s", str);
        } else {
            count += printf("%c", format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}

int main() {
    char text[] = "Hello, world!";
    char format[] = "Original: %s\nROT13: %R\n";

    customPrintf(format, text, text);
    return 0;
}
