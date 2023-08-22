#include "main.h"

/**
 * has_format_tag - checks for % sign.
 *
 * @string: A string.
 *
 * Return: 1 (Success) 0 (Fail)
 */
static int has_format_tag(char *string)
{
	if (strchr(string, '%'))
		return (1);
	return (0);

}

/**
 * send_output - Send a string to STDOUT.
 *
 * @string: A string.
 *
 * Return: The number of chars printed.
 */
int send_output(char *string)
{
	return (write(1, string, strlen(string)));
}

/**
 * _printf - Prints a formatted string.
 *
 * @format: The base string.
 *
 * Description: It can handle the following arguments
 * (converter flags) such as c, s, d, i, and % but no flags.
 *
 * Return: The number of chars printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int tmp_count;
	char *tmp_format;

	if (format == NULL || strcmp(format, "%") == 0)
	{
		return (-1);
	}
	if (!has_format_tag((char *)format))
		return (send_output((char *)format));
	va_start(args, format);
	tmp_format = (char *)format;
	count = tag_handler(&tmp_format, args);
	tmp_count = 1;
	while (*tmp_format && tmp_count != -1)
	{
		tmp_count = tag_handler(&tmp_format, args);
		count += tmp_count;
	}
	va_end(args);
	if (tmp_count == -1)
		return (tmp_count);
	return (count);
}
