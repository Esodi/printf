#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int send_output(char *str);
int tag_agent(char **str, va_list par);
int char_agent(va_list par);
int str_agent(va_list par);
int int_agent(va_list par);
int p_agent(void);
void _putchar_fd(char x, int fd);
char *_substr(char const *s, unsigned int start, size_t len);
char *_itoa(int n);
size_t _intlen(int i);
#endif /*MAIN_H*/
