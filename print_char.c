
#include "main.h"

/**
 * print_char - print a character from va_list
 * @ap: va_list with character to print as next element
 *
 * Return: Number of characters printed.
 */
int print_char(va_list ap)
{
    char c;

    c = va_arg(ap, int);
    write(1, &c, 1);
    return (1);
}
