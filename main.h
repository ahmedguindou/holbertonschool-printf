#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * struct print - Structure to associate
 * format specifiers with corresponding functions.
 * @print: The format specifier character (e.g., 'c', 's', etc.).
 * @p: The function to handle the format specifier.
 */
typedef struct print
{
char *print;
int (*p)();
} print_t;
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_i(va_list args);
int print_d(va_list args);
#endif
