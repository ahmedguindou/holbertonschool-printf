#include "main.h"
/**
 * handle_specifier - Handles the format specifiers.
 * @format: Format string containing the characters and specifiers.
 * @i: The index of the current character in the format string.
 * @arg: The va_list containing the arguments for the format string.
 * @print: Array of print_t structures mapping format specifiers to functions.
 * Return: The number of characters printed for the format specifier.
 **/
int handle_specifier(const char *format,
unsigned int *i, va_list arg, print_t print[])
{
unsigned int j = 0, flag = 0, len = 0;
while (print[j].p != NULL)
{
if (format[*i + 1] == print[j].print[0])
{
len = print[j].p(arg);
flag = 1;
(*i)++;
break;
}
j++;
}
if (flag == 0)
{
_putchar(format[*i]);
len++;
}
return (len);
}
/**
 * _printf - Custom printf function
 * @format: Format string containing the characters and specifiers.
 * Description: This function produces output according to a format string
 * and arguments. It supports the following conversion specifiers:
 * 'c', 's', 'i', 'd', and '%%'.
 * Return: The total number of characters printed on success,
 * or -1 if an error occurs (e.g., NULL format or lone '%').
 **/
int _printf(const char *format, ...)
{
va_list arg;
unsigned int i = 0, len = 0;
print_t print[] = {{"c", print_char}, {"s", print_string},
{"i", print_i}, {"d", print_d}, {NULL, NULL}};
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(arg, format);
while (format[i] != '\0')
{
if (format[i] == '%' && format[i + 1] != '%')
len += handle_specifier(format, &i, arg, print);
else if (format[i] == '%' && format[i + 1] == '%')
{
_putchar('%');
len++;
i++;
}
else
{
_putchar(format[i]);
len++;
}
i++;
}
va_end(arg);
return (len);
}
