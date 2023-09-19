#include "main.h"

/**
 * print_percent - A function to print a '%' character.
 * @types: Variable of type va_list (not used for '%' character).
 * @buffer: where the output will be stored.
 * @flags: Flags that modify the output (not used for '%' chars).
 * @width: Minimum width of the output (not used for '%' chars).
 * @precision: Precision of the output (not used for '%' chars).
 * @size: The size (not used for '%' chars).
 * Return: Number of chars printed (always 1 for '%').
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (handle_write_char('%', buffer, 0, 0, 0, 0));
}
