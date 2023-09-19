#include "main.h"

/**
 * print_unsigned - function to print an unsigned integer.
 * @types: Variable of type  va_list containing the unsigned integer.
 * @buffer: where the output will be stored.
 * @flags: Flags that modify the output (F_MINUS, F_PLUS, F_ZERO, ..).
 * @width: Minimum width of the output (for padding, ..).
 * @precision: Precision of the output (not used for unsigned integers).
 * @size: The size of the integer (S_LONG, S_SHORT, ..).
 * Return: The number of characters printed.
 */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n;

	if (size == S_LONG)
		n = va_arg(types, unsigned long);
	else if (size == S_SHORT)
		n = (unsigned short)va_arg(types, unsigned int);
	else
		n = va_arg(types, unsigned int);
	return (write_unsgnd(n, 0, buffer, flags, width, precision, 0));
}
