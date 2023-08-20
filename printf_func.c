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
	/*void (*f)(const char *, va_list) = switch_func;*/

	VALUES(v);
	va_start(par, format);
	if (format == NULL)
		return (0);
	while (format && *format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			INC(format, v.y);
		}
		else
		{
			INC(format, v.y);
			switch (*format)
			{
				case 'c':
					v.c = (char)va_arg(par, int);
					write(1, &(v.c), 1);
					INC(format, v.y);
					break;
				case 's':
					v.s = va_arg(par, char*);
					printstr(v.s);
					v.y = strlen(v.s) + v.y;
					format++;
					break;
				case '%':
					v.p = '%';
					write(1, &(v.p), 1);
					INC(format, v.y);
					break;
				default:
					return (-1);
			}
		}
	}
	va_end(par);
	return (v.y);
}
