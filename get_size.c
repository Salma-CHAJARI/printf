#include "main.h"

/**
 * get_size - Extracts the size specifier.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * Return: extracted size specifier or 0 if not found.
 */
int get_size(const char *format, int *i)
{
	int curri = *i + 1;
	int size = 0;

	if (format[curri] == 'l')
		size = S_LONG;
	else if (format[curri] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curri - 1;
	else
		*i = curri;

	return (size);
}

