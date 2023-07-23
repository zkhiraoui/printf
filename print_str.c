
#include "main.h"

/**
 * print_str - print a string from va_list
 * @ap: va_list with string to print as next element
 *
 * Return: Number of characters printed.
 */
int print_str(va_list ap)
{
    int i;
    char *str;

    str = va_arg(ap, char *);
    if (str == NULL)
        str = "(null)";
    for (i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return (i);
}
