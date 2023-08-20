#include "main.h"

void _putchar_fd(char x, int fd)
{
	write(fd, &x, sizeof(x));
}
