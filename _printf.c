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
int _printf(const char *format, ...)
{
va_list arg;
unsigned int i, j, flag;
unsigned int len = 0;
print_t print[] = {
{"c", print_char}, {"s", print_string},
{"i", print_i}, {"d", print_d}, {NULL, NULL}
};
va_start(arg, format);
if (format == NULL)
return (-1);
if (format[0] == '%' && format[1] == '\0')
return (-1);
i = 0;
while (format[i] != '\0')
{
if (format[i] == '%' && format[i + 1] != '%')
{
j = 0;
flag = 0;
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
if (flag == 0)
{
_putchar(format[i]);
len += 1;
}
}
else if (format[i] == '%' && format[i + 1] == '%')
{
_putchar('%');
i++;
len += 1;
}
else
{
_putchar(format[i]);
len += 1;
}
i++;
}
va_end(arg);
return (len);
}
