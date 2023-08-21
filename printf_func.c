#include "main.h"

static int has_format_tag(char *string)
{
	if (strchr(string, '%'))
		return (1);
	return (0);
	/*return strchr(string, '%') != NULL;*/
}

int send_output(char *string)
{
	return (write(1, string, strlen(string)));
}

/**
 * _printf - print to std output
 * @format: string
 * Return: length of the string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int tmp_count;
	char *tmp_format;

	if (format == NULL)
		return (-1);
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
