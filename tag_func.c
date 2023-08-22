#include "main.h"

static int tag_caller(char converter, va_list args);
static int prefix_handler(char **string);
static int tag_invalid(char converter);
static char converter_handler(char **string);

/**
 * tag_handler - Deals with the incidence of % in a string.
 *
 * @string: Pointer to a string.
 * @args: A va_list.
 *
 * Return: The number of chars printed.
 */
int tag_handler(char **string, va_list args)
{
	int counter;

	if (**string)
	{
		counter = prefix_handler(string);
		if (counter)
			return (counter);
		return (tag_caller(converter_handler(string), args));
	}
	return (0);
}

/**
 * converter_handler - handles converter.
 *
 * @string: A string.
 *
 * Return: tag.
 */
static char converter_handler(char **string)
{
	char tag;

	tag = (*string)[1];
	*string = *string + 2;
	return (tag);
}

/**
 * tag_caller - calling a tag placed after %.
 *
 * @converter: A placeholder.
 *
 * @args: Arguments.
 *
 * Return: Handler (Success).
 */
static int tag_caller(char converter, va_list args)
{

	if (converter == 'c')
		return (char_handler(args));
	if (converter == 's')
		return (str_handler(args));
	if (converter == 'd' || converter == 'i')
		return (int_handler(args));
	if (converter == '%')
		return (percent_handler());
	else
		return (tag_invalid(converter));
}

/**
 * prefix_handler - handles prefix
 *
 * @string: A string.
 *
 * Return: int.
 */
static int prefix_handler(char **string)
{
	char *tmp_str;
	char *start;
	int counter;

	start = strchr(*string, '%');
	if (!start)
	{
		counter = send_output(*string);
		*string = strchr(*string, '\0');
		return (counter);
	}
	if (!(start - *string))
		return (0);
	tmp_str = _substr(*string, 0, start - *string);
	if (!tmp_str)
		return (-1);
	counter = send_output(tmp_str);
	*string = start;
	free(tmp_str);
	return (counter);
}

/**
 * tag_invalid - Default case.
 *
 * @converter: A placeholder.
 *
 * Return: 2.
 */
static int tag_invalid(char converter)
{
	_putchar_fd('%', 1);
	_putchar_fd(converter, 1);
	return (2);
}
