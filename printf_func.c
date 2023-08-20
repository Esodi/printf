#include "main.h"
/*
void print_digit(int d)
{
	int index = 0;
	int i, num;
	char temp[20];
	char arr[20];

	if (d < 0)
	{
		_putchar('-');
		d = -d;
	}
	if (d == 0)
	{
		_putchar('0');
		return;
	}
	while (d > 0)
	{
		temp[index++] = '0' + (d % 10);
		d /= 10;
	}
	temp[index] = '\0';
	for (i = index - 1; i >+ 0; i--)
	{
		strcpy(arr, temp[i]);
	}
}	*/

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
				case 'd':
				case 'i':
					v.i = va_arg(par, int);
					printf("%d", v.i);
					/*v.y = strlen(v.i) + v.y;*/
					format++;
					break;
				default:
					return (-1);
			}
		}
	}
	va_end(par);
	return (v.y);
}
