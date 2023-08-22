#include "main.h"

/**
 * int_agent - Handles integer formatting and output
 * @par: A variable argument list containing the integer to be formatted
 *
 * Return: The number of characters written to the output.
 */

int int_agent(va_list par)
{
	char *string;
	int integer;
	int counter;

	integer = va_arg(par, int);
	string = _itoa(integer);
	counter = send_output(string);
	free(string);
	return (counter);
}
