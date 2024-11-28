#include "main.h"
/**
* _printf - Print formatted string.
* @format: The format string.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list arg;
unsigned int i, j, len = 0;
print_t print[] = {
{"c", print_char}, {"s", print_string},
{"i", print_i}, {"d", print_d}, {NULL, NULL}
};
va_start(arg, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (0);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i + 1] != '%')
{
for (j = 0; print[j].p != NULL; j++)
if (format[i + 1] == print[j].print[0])
{
len += print[j].p(arg);
i++;
break;
}
if (print[j].p == NULL)
_putchar(format[i]);
}
else if (format[i] == '%' && format[i + 1] == '%')
{
_putchar('%');
i++;
}
else
_putchar(format[i]);
}
len++;
va_end(arg);
return (len);
}
