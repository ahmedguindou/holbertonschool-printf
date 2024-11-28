#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string containing the characters and specifiers
 * Description: This function produces output according to a format string
 * and arguments. It supports the following conversion specifiers:
 * 'c', 's', 'i', 'd', and '%%'.
 * Return: The total number of characters printed on success,
 * or -1 if an error occurs (e.g., NULL format or lone '%').
 */
#include "main.h"
int _printf(const char *format, ...)
{
va_list arg;
unsigned int i = 0, len = 0;
print_t print[] = {
{"c", print_char}, {"s", print_string},
{"i", print_i}, {"d", print_d}, {NULL, NULL}
};
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(arg, format);
while (format[i] != '\0')
{
if (format[i] == '%' && format[i + 1] != '%')
{
unsigned int j = 0, flag = 0;
while (print[j].p != NULL)
{
if (format[i + 1] == print[j].print[0])
{
len += print[j].p(arg);
flag = 1;
i++;
}
j++;
}
if (!flag)
_putchar(format[i]);
}
else if (format[i] == '%' && format[i + 1] == '%')
_putchar('%');
else
_putchar(format[i]);
len += 1;
i++;
}
va_end(arg);
return (len);
}
