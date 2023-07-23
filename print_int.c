
#include "main.h"

/**
 * print_int - print an integer from va_list
 * @ap: va_list with integer to print as next element
 *
 * Return: Number of characters printed.
 */
int print_int(va_list ap)
{
    int i, num, temp, len, count;
    num = va_arg(ap, int);
    len = 0;
    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (num < 0)
    {
        len++;
        write(1, "-", 1);
        num *= -1;
    }
    temp = num;
    while (temp != 0)
    {
        len++;
        temp /= 10;
    }
    for (count = len - 1; count >= 0; count--)
    {
        temp = num;
        for (i = 0; i < count; i++)
        {
            temp /= 10;
        }
        temp %= 10;
        write(1, &"0123456789"[temp], 1);
    }
    return (len);
}
