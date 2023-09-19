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
	char *str = va_arg(types, char *);
	int nbr_print = 0;

	if (str == NULL)
		str = "(null)";
	do {
		nbr_print += handle_write_char(*str, buffer, 0, 0, 0, 0);
		str++;
	} while (*str)
	return (nbr_print);
}
