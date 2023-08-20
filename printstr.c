#include "main.h"

/**
 * _putchar - prints a char
 * @q: char
 * Return: char
 */
int _putchar(char q)
{
	return (write(1, &q, 1));
}

/**
 * printstr - prints a string
 * @s: string
 */
void printstr(char *s)
{
	while (*s)
	{
		_putchar(*s++);
	}
}
