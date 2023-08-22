#include "main.h"

/**
 * _putchar_fd - puts a character
 *
 * @x: a char
 *
 * @fd: an int
 */
void _putchar_fd(char x, int fd)
{
	write(fd, &x, sizeof(x));
}
