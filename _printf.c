#include "main.h"
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    print_char(args);
                    break;
                case 's':
                    print_string(args);
                    break;
                case '%':
                    print_percent();
                    break;
                default:
                    return (-1);
            }
        }
        else
        {
            write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return (0);
}

void print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
}

void print_string(va_list args)
{
    char *s = va_arg(args, char*);
    while (*s)
    {
        write(1, s++, 1);
    }
}

