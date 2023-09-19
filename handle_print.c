#include "main.h"

/**
 * handle_print - Handles the printing of formatted data to a buffer.
 * @fmt: The format string.
 * @i: Pointer to the current position in the format string.
 * @list: The va_list of arguments.
 * @buffer: The buffer to write to.
 * @flags: Formatting flags.
 * @width: Minimum width for the output.
 * @precision: Precision for the output.
 * @size: Size specifier (e.g., short or long).
 * Return: Number of chars written to the buffer.
 */
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int written = 0, j;

	while (fmt[*i] && fmt[*i] != '%')
	{
		written += _putchar(fmt[(*i)++]);
	}

	if (fmt[*i] == '%')
	{
		(*i)++;

		if (fmt[*i] == '%')
			return (written + _putchar('%'));
		for (j = 0; format_specifiers[j].fmt; j++)
		{
			if (fmt[*i] == format_specifiers[j].fmt)
				return (written + format_specifiers[j].fn(list,
							buffer, flags, width, precision, size));
		}
	}

	return (written);
