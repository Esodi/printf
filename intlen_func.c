#include "main.h"

/**
 * _intlen - len of int.
 *
 * @i: An integer
 *
 * Return: Size
 */
size_t _intlen(int i)
{
	size_t size;

	size = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		size++;
		i = i / 10;
	}
	return (size);
}
