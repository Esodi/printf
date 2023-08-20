#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct var - contains variables
 * @c: char var
 * @p: char var
 * @s: string
 * @x: int var
 * @y: int var
 */
typedef struct var
{
	char c;
	char p;
	char *s;
	int x;
	int y;
	int i;
	int d;
} var;

#define INC(format, y) \
	do {format++; \
		y++; }  \
		while (0)
/*#define VAR(par, b) do {va_list par; var b;} while (0)*/
#define VALUES(v) do { \
	(v.x) = 0; \
	(v.y) = 0; \
} while (0)

int _putchar(char q);
void printstr(char *s);
int _printf(const char *format, ...);
void switch_func(const char *format, va_list par);

#endif /*MAIN.H*/
