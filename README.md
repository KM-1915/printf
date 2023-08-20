# Custom `printf` Function

This repository contains the implementation of a custom `printf` function in C. The purpose of this project is to demonstrate the process of creating a simplified version of the standard library's `printf` function, which is used for formatting and printing output to the console or other output streams.

## Overview

The custom `printf` function replicates the core functionality of the standard `printf`, including support for format specifiers, variable argument lists, width and precision specifiers, flags, and escape sequences.
## Supported Format Specifiers

The custom printf function supports the following format specifiers:

- `%d`: Signed integer
- `%u`: Unsigned integer
- `%x`: Unsigned integer in hexadecimal (lowercase)
- `%X`: Unsigned integer in hexadecimal (uppercase)
- `%c`: Character
- `%s`: String
- `%f`: Floating-point number
- `%%`: Escape sequence for a literal '%'


## Testing

The `test_custom_printf.c` file contains various test cases to validate the functionality of the custom printf function. You can compile and run this test file to check for correct output.

Happy coding! 🚀

## Usage

The custom `printf` function is used just like the standard `printf`. You can format and print output using format specifiers:

```c
#include "main.h"

int main() 
{
    int num = 42;
    char* str = "Hello, Custom Printf";

    custom_printf("Integer: %d, String: %s\n", num, str);

    return 0;
}
