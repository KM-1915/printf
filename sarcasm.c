#include <stdio.h>
#include <stdarg.h>

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
                if (format[i] == 'd') {
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
                // Handle 'h' modifier (short)
                // Similar logic as above, just for short types
            } else if (format[i] == 'd' || format[i] == 'i') {
                int num = va_arg(args, int);
                count += printf("%d", num);
            } else if (format[i] == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                count += printf("%u", num);
            } else if (format[i] == 'o') {
                unsigned int num = va_arg(args, unsigned int);
                count += printf("%o", num);
            } else if (format[i] == 'x' || format[i] == 'X') {
                unsigned int num = va_arg(args, unsigned int);
                count += printf(format[i] == 'x' ? "%x" : "%X", num);
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

int main() {
    int a = 42;
    long b = 1234567890L;
    unsigned int c = 98765;
    
    custom_printf("Int: %d\n", a);
    custom_printf("Long: %ld\n", b);
    custom_printf("Unsigned Int: %u\n", c);
    
    return 0;
}
