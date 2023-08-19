#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct var
{
	char c;
	char p;
	char *s;
	int x;
	int y;
} var;

#define INC(format, y) do {format++; y++;} while(0)
#define VAR(par, b) do {va_list par; var b;} while(0)
#define VALUES(v) do { \
	v.x = 0; \
	v.y = 0; \
} while (0)
#define CHECK_FORMAT(format) \
	if ((format) == NULL) \
	return 0
int _putchar(char q);
void printstr(char *s);

#endif /*MAIN.H*/
