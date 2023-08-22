#include "main.h"

/**
 * int_handler - Deals with i or d converter in a string.
 *
 * @args: A va_list.
 *
 * Return: The number of chars printed.
 */
int int_handler(va_list args)
{
	char *string;
	int integer;
	int counter;

	integer = va_arg(args, int);
	string = _itoa(integer);
	counter = send_output(string);
	free(string);
	return (counter);
}
