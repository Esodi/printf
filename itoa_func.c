#include "main.h"
char *_itoa(int n)
{
	size_t i;
	size_t minus;
	char *p;

	i = _intlen(n);
	minus = (n < 0);
	i += minus;
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	p[i] = '\0';
	if (minus)
		p[0] = '-';
	while (--i != (minus - 1))
	{
		if ((n % 10) < 0)
			p[i] = ((n % 10) * -1) + 48;
		else
			p[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (p);
}
