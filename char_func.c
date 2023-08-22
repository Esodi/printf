#include "main.h"


/**
 * char_handler - Deals with the incidence of the c converter in a string.
 *
 * @args: A va_list.
 *
 * Return: The number of chars printed.
 */
int char_handler(va_list args)
{
	int counter;
	char to_print;
	char *string;

	to_print = va_arg(args, int);
	if (!to_print)
	{
		write(1, &to_print, 1);
		return (1);
	}
	string = calloc(sizeof(char), 2);
	string[0] = to_print;
	counter = send_output(string);
	free(string);
	return (counter);
}

/**
 * str_handler - Deals with the incidence of the s converter in a string.
 *
 * @args: A va_list.
 *
 * Return: The number of chars printed.
 */
int str_handler(va_list args)
{
	char *string;
	int counter;
	char *pointer;

	pointer = va_arg(args, char *);
	if (!pointer)
		return (write(1, "(nill)", 6));
	string = strdup(pointer);
	counter = send_output(string);
	free(string);
	return (counter);
}

/**
 * percent_handler - Deals with double % converters in a string.
 *
 * Return: The number of chars printed.
 */
int percent_handler(void)
{
	return (write(1, "%", 1));
}
