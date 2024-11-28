#include "main.h"
#include <stdarg.h>
/**
 * _printf - Custom printf implementation
 * @format: Format string with specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list arg;
unsigned int i = 0, j, len = 0;
print_t _print_int[] = {
{"c", _print_char}, {"s", _print_string}, {"i", _print_int}, {NULL, NULL}
};
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (0);

}
