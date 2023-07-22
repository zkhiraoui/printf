#include <stdarg.h>
#include <stdio.h>

void print_integer(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    if (n == 0) {
        putchar('0');
    }

    int temp = n, count = 0;
    while (temp != 0) {
        count++;
        temp /= 10;
    }

    for (int i = 0; i < count; i++) {
        temp = n;
        for (int j = 0; j < count - i - 1; j++) {
            temp /= 10;
        }
        putchar((temp % 10) + '0');
    }
}

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    int i;

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
                for (int j = 0; s[j] != '\0'; j++) {
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
            case 'd':
            case 'i': {
                int num = va_arg(args, int);
                print_integer(num);
                break;
            }
            default: {
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
