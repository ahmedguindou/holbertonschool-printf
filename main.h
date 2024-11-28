#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_int(va_list args);
#endif
