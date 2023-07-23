#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

void print_number(int n) {
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    if (n / 10)
        print_number(n / 10);

    _putchar((n % 10) + '0');
}

void print_unsigned_number(unsigned int n) {
    if (n / 10)
        print_unsigned_number(n / 10);

    _putchar((n % 10) + '0');
}

void print_hex(unsigned int n, int capital) {
    char hex[17] = capital ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        print_hex(n / 16, capital);

    _putchar(hex[n % 16]);
}

void print_pointer(void *p) {
    unsigned long int n = (unsigned long int)p;
    _putchar('0');
    _putchar('x');
    print_hex(n, 0);
}

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            _putchar(format[i]);
            count++;
        }
        else {
            i++; // increment to character after '%'
            switch (format[i]) {
                case 'c': { 
                    char c = va_arg(args, int); // char arguments are promoted to int in ...
                    _putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    for (int j = 0; str[j]; j++) {
                        _putchar(str[j]);
                        count++;
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    count++;
                    break;
                case 'd':
                case 'i': {
                    int n = va_arg(args, int);
                    print_number(n);
                    break;
                }
                case 'u': {
                    unsigned int n = va_arg(args, unsigned int);
                    print_unsigned_number(n);
                    break;
                }
                case 'o': {
                    unsigned int n = va_arg(args, unsigned int);
                    _putchar('0');
                    print_hex(n, 8); // print in octal
                    break;
                }
                case 'x': {
                    unsigned int n = va_arg(args, unsigned int);
                    print_hex(n, 0); // print in lowercase hexadecimal
                    break;
                }
                case 'X': {
                    unsigned int n = va_arg(args, unsigned int);
                    print_hex(n, 1); // print in uppercase hexadecimal
                    break;
                }
                case 'p': {
                    void *p = va_arg(args, void *);
                    print_pointer(p);
                    break;
                }
                default:
                    // for any unrecognized pattern
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
            }
        }
    }

    va_end(args); // cleanup
    return count;
}

