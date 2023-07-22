#include "main.h"
#include <unistd.h>

static int put_char(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;
    
    for (const char *ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr != '%') {
            char_count += put_char(*ptr);
            continue;
        }

        char specifier = *++ptr;
        switch (specifier) {
            case 'c': {
                char c = (char)va_arg(args, int);
                char_count += put_char(c);
                break;
            }
            case 's': {
                const char *str = va_arg(args, const char *);
                for (; *str != '\0'; str++)
                    char_count += put_char(*str);
                break;
            }
            case '%':
                char_count += put_char('%');
                break;
            default:
                char_count += put_char('%');
                char_count += put_char(specifier);
                break;
        }
    }

    va_end(args);

    return char_count;
}
