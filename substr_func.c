#include "main.h"

char *_substr(char const *s, unsigned int start, size_t len)
{
	char *p;
	size_t substring_length;
	size_t input_length = strlen(s);

	if (start >= input_length)
	{
		p = (char *)malloc(1);
		if (p == NULL) 
		{
			return NULL;
		}
		p[0] = '\0';
		return p;
	}
	substring_length = input_length - start;
	if (substring_length > len) 
	{
		substring_length = len;
	}
	p = (char *)malloc(substring_length + 1);
	if (p == NULL) 
	{
		return NULL;
	}
	strncpy(p, &s[start], substring_length);
	p[substring_length] = '\0';
	return (p);
}

