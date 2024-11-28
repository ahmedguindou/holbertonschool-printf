#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
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
