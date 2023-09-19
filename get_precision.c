#include "main.h"

/**
 * get_precision - Extracts the precision specifier.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * @list: va_list of arguments (unused).
 *
 * Return: extracted precision specifier or -1 if not found.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	UNUSED(list);

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			(*i)++;
			precision = va_arg(list, int);
		}
		else
		{
			precision = 0;

			while (format[*i] && is_digit(format[*i]))
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	return (precision);
}
