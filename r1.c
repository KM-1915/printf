#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char text[] = "Hello, world!";
    char format[] = "Original: %s\nReversed: %r\n";

    printf(format, text, text);
    return 0;
}
