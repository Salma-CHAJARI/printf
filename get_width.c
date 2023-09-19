#include "main.h"

/**
 * get_width - Extracts the width specifier.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * @list: va_list of arguments (unused).
 * Return: extracted width specifier or 0 if not found.
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	UNUSED(list);

	while (format[*i] && is_digit(format[*i]))
	{
		width = width * 10 + (format[*i] - '0');
		(*i)++;
	}

	return (width);
}
