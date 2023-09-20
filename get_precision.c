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
	int curri = *i + 1;
	int precision = -1;

	if (format[curri] != '.')
		return (precision);

	precision = 0;

	for (curri += 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			precision *= 10;
			precision += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curri - 1;
	return (precision);

}
