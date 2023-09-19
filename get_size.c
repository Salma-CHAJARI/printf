#include "main.h"

/**
 * get_size - Extracts the size specifier.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * Return: extracted size specifier or 0 if not found.
 */
int get_size(const char *format, int *i)
{
	int size = 0;

	if (format[*i] == 'h' || format[*i] == 'l')
	{
		if (format[*i] == 'h' && format[(*i) + 1] == 'h')
		{
			size = S_CHAR;
			(*i) += 2;
		}
		else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
		{
			size = S_LONG_LONG;
			(*i) += 2;
		}
		else if (format[*i] == 'h')
		{
			size = S_SHORT;
			(*i)++;
		}
		else if (format[*i] == 'l')
		{
			size = S_LONG;
			(*i)++;
		}
	}

	return (size);
}
