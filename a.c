#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output (stdout)
 *
 * @c: Character to write
 *
 * Return: Upon success, returns the character written as an int. Otherwise, -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - A simplified printf function
 *
 * @format: The format string
 * ...: Additional arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Skip the '%' */

            switch (*format)
            {
                case 'c': /* char */
                    _putchar(va_arg(args, int)); /* chars are promoted to int in ... */
                    count++;
                    break;
                case 's': /* string */
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': /* literal '%' */
                    _putchar('%');
                    count++;
                    break;
                default: /* Invalid format specifier, ignore it */
                    break;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
