#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(void);

#endif /* MAIN_H */

