#include "main.h"

static int tag_caller(char converter, va_list par);
static int prefix_agent(char **str);
static int tag_invalid(char converter);
static char converter_agent(char **str);

/**
 * tag_agent - Deals with the incidence of % in a string.
 *
 * @str: Pointer to a string.
 * @par: A va_list.
 *
 * Return: The number of chars printed.
 */
int tag_agent(char **str, va_list par)
{
	int counter;

	if (**str)
	{
		counter = prefix_agent(str);
		if (counter)
			return (counter);
		return (tag_caller(converter_agent(str), par));
	}
	return (0);
}

/**
 * converter_agent - handles converter.
 *
 * @str: A string.
 *
 * Return: tag.
 */
static char converter_agent(char **str)
{
	char tag;

	tag = (*str)[1];
	*str = *str + 2;
	return (tag);
}

/**
 * tag_caller - calling a tag placed after %.
 *
 * @converter: A placeholder.
 *
 * @par: Arguments.
 *
 * Return: Handler (Success).
 */
static int tag_caller(char converter, va_list par)
{

	if (converter == 'c')
		return (char_agent(par));
	if (converter == 's')
		return (str_agent(par));
	if (converter == 'd' || converter == 'i')
		return (int_agent(par));
	if (converter == '%')
		return (p_agent());
	else
		return (tag_invalid(converter));
}

/**
 * prefix_agent - handles prefix
 *
 * @str: A string.
 *
 * Return: int.
 */
static int prefix_agent(char **str)
{
	char *tmp_str;
	char *start;
	int counter;

	start = strchr(*str, '%');
	if (!start)
	{
		counter = send_output(*str);
		*str = strchr(*str, '\0');
		return (counter);
	}
	if (!(start - *str))
		return (0);
	tmp_str = _substr(*str, 0, start - *str);
	if (!tmp_str)
		return (-1);
	counter = send_output(tmp_str);
	*str = start;
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
