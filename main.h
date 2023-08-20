#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int send_output(char *string);
int tag_handler(char **string, va_list args);
int char_handler(va_list args);
int str_handler(va_list args);
int int_handler(va_list args);
int uint_handler(va_list args);
int ptr_handler(va_list args);
int hex_handler(char converter, va_list args);
int percent_handler(void);
void _putchar_fd(char x, int fd);
char *_substr(char const *s, unsigned int start, size_t len);
char *_itoa(int n);
size_t _intlen(int i);

#endif /*MAIN_H*/
