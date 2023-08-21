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
