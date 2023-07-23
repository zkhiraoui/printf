#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: format string to print
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
    int i, count = 0;
    va_list ap;
    int (*print_func)(va_list);

    va_start(ap, format);
    for (i = 0; format != NULL && format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    print_func = print_char;
                    break;
                case 's':
                    print_func = print_str;
                    break;
                case 'd':
                case 'i':
                    print_func = print_int;
                    break;
                case '%':
                    write(1, &format[i], 1);
                    count++;
                    continue;
                default:
                    continue;
            }
            count += print_func(ap);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
    }
    va_end(ap);
    return (count);
}
