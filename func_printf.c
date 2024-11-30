#include "main.h"
#include <stdlib.h>

/**
 * _print_char - Prints a character from variadic arguments.
 * @args: The list of arguments containing the character.
 * Return: Always 1 (number of characters printed).
 **/

int _print_char(va_list args)
{
char c;
c = va_arg(arg, int);
_putchar(c);
return (1);
}
/**
 * _print_string - Prints a string from variadic arguments.
 * @args: The list of arguments containing the string.
 * Return: The number of characters printed.
 */
int _print_string(va_list args)
{
unsigned int i;
char *s;
s = va_arg(arg, char *);
if (s == NULL)
s = "(null)";
for (i = 0; s[i] != '\0'; i++)
{
_putchar(s[i]);
}
return (i);
}
/**
 * _print_int - Prints an integer from variadic arguments.
 * @args: The list of arguments containing the integer.
 * Return: The number of characters printed.
 */
int _print_int(va_list args)
{
int x = va_arg(arg, int);
int n;
int last;
int digit;
int exp = 1;
int i = 1;
x = x / 10;
n = x;
last = n % 10;
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
