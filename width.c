#include <stdio.h>

int main() {
    int intValue = 12345;
    float floatValue = 3.14159;
    char charValue = 'A';
    
    // Handling field width for integer value
    printf("Integer with width 10: |%10d|\n", intValue);
    printf("Integer with width 5:  |%5d|\n", intValue);
    
    // Handling field width for floating-point value
    printf("Float with width 10:   |%10f|\n", floatValue);
    printf("Float with width 7:    |%7f|\n", floatValue);
    
    // Handling field width for character value
    printf("Char with width 5:     |%5c|\n", charValue);
    
    return 0;
}
