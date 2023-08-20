#include "main.h"

/**
 * switch_func - establish switch case
 * @format: choice
 * @par: arguments
 */
void switch_func(const char *format, va_list par)
{
	var v;

	INC(format, v.y);
	switch (format[v.x])
	{
		case 'c':
			v.c = (char)va_arg(par, int);
			write(1, &(v.c), 1);
			break;
		case 's':
			v.s = va_arg(par, char*);
			printstr(v.s);
			INC(format, v.y);
			break;
		case '%':
			v.p = '%';
			write(1, &(v.p), 1);
			INC(format, v.y);
			break;
		default:
			return;
	}
}
