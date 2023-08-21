#include <stdio.h>

int main() {
    int num = 12345;
    float floatNum = 123.456;
    char character = 'A';

    printf("Default formatting:\n");
    printf("Integer: %d\n", num);
    printf("Float: %f\n", floatNum);
    printf("Character: %c\n", character);

    printf("\nLeft-justified formatting:\n");
    printf("Integer: %-10d|\n", num);
    printf("Float: %-10f|\n", floatNum);
    printf("Character: %-10c|\n", character);

    return 0;
}
