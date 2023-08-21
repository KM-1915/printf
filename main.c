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
