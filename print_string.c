#include "main.h"

/**
 * print_string - A fonction to print a string.
 * @types: of type va_list containing the string to be printed.
 * @buffer: where the output will be stored.
 * @flags: Flags that modify the output (not used for string).
 * @width: Minimum width of the output (not used for string).
 * @precision: Precision of the output (not used for string).
 * @size: The size of the string (not used for string).
 * Return: The number of chars printed.
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
