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
	int curri, width = 0;

	for (curri = *i + 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			width *= 10;
			width += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curri - 1;
	return (width);

}
