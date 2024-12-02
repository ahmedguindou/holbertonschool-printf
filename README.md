# Custom _printf Function

## Overview

This project implements a custom version of the standard printf function in C, named _printf. The function generates formatted output based on a format string and arguments. It supports the following conversion specifiers:

- %c: Prints a single character.
- %s: Prints a string.
- %i and %d: Prints an integer.
- %%: Prints a literal % character.

The implementation adheres to structured and efficient coding practices, ensuring modularity and clarity.

---

## File Structure

### main.h
The header file includes all necessary function prototypes and definitions used across the implementation. It also defines the print_t structure to map format specifiers to their respective functions.

### _printf
The main function that handles formatted output based on the format string and arguments.

### handle_specifier
This helper function processes format specifiers and maps them to their corresponding functions defined in the print_t structure.

### print_char
Handles the %c specifier by printing a single character from the variadic arguments.

### print_string
Handles the %s specifier by printing a string from the variadic arguments.

### print_i and print_d
Both handle integer printing using the same logic for signed decimal numbers.

### _putchar
Writes a single character to the standard output.

---

## Function Descriptions

### _printf
c
int _printf(const char *format, ...);

*Parameters:*
- format: The format string containing characters and specifiers.

*Return Value:*
- Returns the total number of characters printed on success.
- Returns -1 if an error occurs (e.g., NULL format or a lone %).

*Description:*
The _printf function iterates over the format string, identifying characters and specifiers. It delegates the handling of specifiers to the handle_specifier function. For literal % characters, it prints them directly. Non-specifier characters are printed as-is.

---

### handle_specifier
c
int handle_specifier(const char *format, unsigned int *i, va_list arg, print_t print[]);

*Parameters:*
- format: The format string containing characters and specifiers.
- i: A pointer to the current index of the format string.
- arg: A va_list containing the arguments for the format string.
- print: An array of print_t structures mapping format specifiers to functions.

*Return Value:*
- Returns the number of characters printed for the format specifier.

*Description:*
The handle_specifier function matches the current format specifier against the print_t structure. If a match is found, the corresponding function is invoked to print the argument. If no match is found, the specifier is printed as-is.

---

### print_char
c
int print_char(va_list args);

*Parameters:*
- args: The list of variadic arguments containing the character.

*Return Value:*
- Always returns 1 (the number of characters printed).

*Description:*
Retrieves a character from the variadic arguments and prints it using _putchar.

---

### print_string
c
int print_string(va_list args);

*Parameters:*
- args: The list of variadic arguments containing the string.

*Return Value:*
- Returns the number of characters printed.

*Description:*
Prints a string from the variadic arguments. If the string is NULL, it prints (null).

---

### print_i and print_d
c
int print_i(va_list args);
int print_d(va_list args);

*Parameters:*
- args: The list of variadic arguments containing the integer.

*Return Value:*
- Returns the number of characters printed.

*Description:*
Prints an integer from the variadic arguments. Handles negative numbers and ensures correct formatting.

---

### _putchar
c
int _putchar(char c);

*Parameters:*
- c: The character to print.

*Return Value:*
- Returns 1 on success, or -1 on error.

*Description:*
Writes a single character to the standard output using the write system call.

---
## Requirements
Operating System: Linux-based systems (e.g., Ubuntu 20.04 LTS).

Compiler: gcc with support for the -std=gnu89 standard.

Style: Code adheres to the Betty coding style.


## Usage Example
c
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, world!");
    _printf("Integer: %d\n", 42);
    _printf("Percent sign: %%\n");

    _printf("Total characters printed: %d\n", len);
    return (0);
}

---

## Testing
To test the implementation, create a variety of test cases using supported specifiers and edge cases. Compare the output of _printf to that of the standard printf function to ensure correctness.

---

## Limitations
- The implementation does not support all specifiers available in the standard printf.
- Error handling is limited to basic checks (e.g., NULL format string).

---

## Future Improvements
- Add support for additional specifiers (e.g., %u, %x, %o).
- Implement buffer handling to optimize output operations.
- Enhance error handling for edge cases.

---

## Author
This implementation was developed by Ahmed Guindou and Rassil Jdidi as part of a project to deepen understanding of variadic functions in C.
