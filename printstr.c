#include "main.h"

int _putchar(char q)
{
	return (write(1, &q, 1));
}

void printstr(char *s)
{
	while (*s)
	{
		_putchar(*s++);
	}
}
