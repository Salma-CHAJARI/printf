#include "main.h"

/**
 * print_char - A Function to print a character.
 * @types: variable of type va_list containing the character to be printed.
 * @buffer: Where the output will be stored.
 * @flags: Flags that modify the output (not used for chars).
 * @width: Minimum width of the output (not used for chars).
 * @precision: Precision of the output (not used for chars).
 * @size: The size of the character (not used for chars).
 * Return: Number of chars printed.
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (handle_write_char(c, buffer, 0, 0, 0, 0));
}
