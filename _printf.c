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
va_start(arg, format);
while (format[i])
{
if (format[i] == '%' && format[i + 1] != '%')
{
j = 0;
while (_print_int[j].specifier)
{
if (format[i + 1] == _print_int[j].specifier[0])
{
len += _print_int[j].p(arg);
i++, j = -1;
break;
}
j++;
}
if (j != -1)
_putchar(format[i]);
len++;
}
else if (format[i] == '%' && format[i + 1] == '%')
_putchar('%'), i++, len++;
else
_putchar(format[i]), len++;
i++;
}
va_end(arg);
return (len);
}
