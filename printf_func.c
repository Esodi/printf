#include "main.h"

/**
 * _printf - print out its arguments and returns the number of the string
 * @format: character string
 * Return: number of strings printed
 */
int _printf(const char *format, ...)
{
	var v;
	va_list par;
	void (*f)(const char*, va_list) = switch_func;

	VALUES(v);
	va_start(par, format);
	if (format == NULL)
		return (0);
	while (format && format[v.x] != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			INC(format, v.y);
		}
		else
		{
			INC(format, v.y);
			f(format, par);
		}
	}
	va_end(par);
	return (v.y);
}
