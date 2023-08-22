#include "main.h"

/**
 * the_tag - checks for % sign.
 *
 * @string: A string.
 *
 * Return: 1 (Success) 0 (Fail)
 */
static int the_tag(char *string)
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
 * _printf - Prints a string.
 * @format: The base string.
 * Return: The number of chars printed.
 */
int _printf(const char *format, ...)
{
	va_list par;
	int len;
	int tmp_L;
	char *tmp_F;

	if (format == NULL || strcmp(format, "%") == 0)
	{
		return (-1);
	}
	if (!the_tag((char *)format))
		return (send_output((char *)format));
	va_start(par, format);
	tmp_F = (char *)format;
	len = tag_agent(&tmp_F, par);
	tmp_L = 1;
	while (*tmp_F && tmp_L != -1)
	{
		tmp_L = tag_agent(&tmp_F, par);
		len += tmp_L;
	}
	va_end(par);
	if (tmp_L == -1)
		return (tmp_L);
	return (len);
}
