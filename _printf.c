#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    int i, j;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            putchar(format[i]);
            count++;
            continue;
        }

        i++;

        switch (format[i]) {
            case 'c': {
                char c = (char)va_arg(args, int);
                putchar(c);
                count++;
                break;
            }
            case 's': {
                char *s = va_arg(args, char *);
                for (j = 0; s[j] != '\0'; j++) {
                    putchar(s[j]);
                    count++;
                }
                break;
            }
            case '%': {
                putchar('%');
                count++;
                break;
            }
            default: {
                /* For any other character after '%', print both '%' and that character. */
                putchar('%');
                putchar(format[i]);
                count += 2;
                break;
            }
        }
    }

    va_end(args);
    return count;
}
