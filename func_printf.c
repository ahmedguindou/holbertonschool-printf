#include "main.h"
#include <stdlib.h>

/**
 * print_char - Prints a character from variadic arguments.
 * @args: The list of arguments containing the character..
 * Return: Always 1 (number of characters printed).
 **/
int print_char(va_list args)
{
char c;
c = va_arg(args, int);
_putchar(c);
return (1);
}
/**
 * print_string - Prints a string from variadic arguments.
 * @args: The list of arguments containing the string.
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
unsigned int i;
char *s;
s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
for (i = 0; s[i] != '\0'; i++)
{
_putchar(s[i]);
}
return (i);
}
/**
 * print_i - Prints an integer from variadic arguments.
 * @args: The list of arguments containing the integer.
 * Return: The number of characters printed.
 */
int print_i(va_list args)
{
int x = va_arg(args, int);
int n;
int last;
int digit;
int exp = 1;
int i = 1;
last = x % 10;
x = x / 10;
n = x;
if (last < 0)
{
_putchar('-');
n = -n;
x = -x;
last = -last;
i++;
}
if (n > 0)
{
while (n / 10 != 0)
{
exp = exp * 10;
n = n / 10;
}
n = x;
while (exp > 0)
{
digit = n / exp;
_putchar(digit + '0');
n = n - (digit *exp);
exp = exp / 10;
i++;
}
}
_putchar(last + '0');
return (i);
}
/**
 * print_d - Prints a decimal
 * @args: va_list containing the decimal to print
 * Return: Number of characters printed
 */
int print_d(va_list args)
{
return (print_i(args));
}
