#include "main.h"

/**
 * print_hexadecimal - Function to print a hexadecimal integer.
 * @types: Variable of va_list containing the hexadecimal integer to be printed
 * @buffer: where the output will be stored.
 * @flags: Flags that modify the output (F_MINUS, F_PLUS, F_ZERO, ..).
 * @width: Minimum width of the output (for padding, ..).
 * @precision: Precision of the output (not used for hexadecimal integer).
 * @size: The size of the integer (S_LONG, S_SHORT, ..).
 * Return: Number of chars printed.
 */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int a;

	if (size == S_LONG)
		a = va_arg(types, unsigned long);
	else if (size == S_SHORT)
		a = (unsigned short)va_arg(types, unsigned int);
	else
		a = va_arg(types, unsigned int);
	return (write_num(0, n, buffer, flags, width, precision, 16));
}
