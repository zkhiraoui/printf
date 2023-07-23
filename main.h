#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
int print_binary(va_list ap);

#endif /* MAIN_H */
