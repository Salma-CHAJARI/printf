#include "main.h"

/**
 * print_int - A function to print an integer.
 * @types: Variable of type va_list containing the integer to be printed.
 * @buffer: where the output will be stored.
 * @flags: Flags that modify the output (F_MINUS, F_PLUS, F_ZERO, ..).
 * @width: Minimum width of the output (for padding, ..).
 * @precision: Precision of the output (not used for integers).
 * @size: The size of the integer (S_LONG, S_SHORT, ..).
 * Return: Number of chars printed.
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int n;
	char sing = '\0';

	if (size == S_LONG)
		n = va_arg(types, long);
	else if (size == S_SHORT)
		n = (short)va_arg(types, int);
	else
		n = va_arg(types, int);
	if (n < 0)
	{
		sing = '-';
		n = -n;
	}
	else if (flags & F_PLUS)
		sing = '+';
	else if (flags & F_SPACE)
		sing = ' ';

	return (write_number(1, n, buffer, flags, width, precision, 0)
			+ handle_write_char(sign, buffer, 0, 0, 0, 0));
}
