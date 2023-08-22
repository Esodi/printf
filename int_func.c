#include "main.h"

/**
 * int_handler - Handles integer formatting and output
 * @args: A variable argument list containing the integer to be formatted
 *
 * Return: The number of characters written to the output.
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
