#include "main.h"


/**
 * char_agent - Deals with the c converter in a string.
 *
 * @par: A va_list.
 *
 * Return: The number of chars printed.
 */
int char_agent(va_list par)
{
	int counter;
	char P;
	char *string;

	P = va_arg(par, int);
	if (!P)
	{
		write(1, &P, 1);
		return (1);
	}
	string = calloc(sizeof(char), 2);
	string[0] = P;
	counter = send_output(string);
	free(string);
	return (counter);
}

/**
 * str_agent - deals with the incidence of the s converter in a string.
 *
 * @par: A va_list.
 *
 * Return: The number of chars printed.
 */
int str_agent(va_list par)
{
	char *string;
	int counter;
	char *pointer;

	pointer = va_arg(par, char *);
	if (!pointer)
		return (write(1, "(nill)", 6));
	string = strdup(pointer);
	counter = send_output(string);
	free(string);
	return (counter);
}

/**
 * p_agent - Deals with double % converters in a string.
 *
 * Return: The number of chars printed.
 */
int p_agent(void)
{
	return (write(1, "%", 1));
}
