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
