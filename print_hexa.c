#include "main.h"

/**
 * print_hexa - function to print a hexadecimal integer.
 * @types: Variable of va_list containing the hexadecimal integer to be printed
 * @map_to: An array containing custom character mapping ("0123456789ABCDEF").
 * @buffer: The buffer where the output will be stored.
 * @flags: Flags that modify the output (F_MINUS, F_PLUS, F_ZERO).
 * @flag_ch: The character representing the hexadecimal prefix ('x', 'X', 'p').
 * @width: Minimum width of the output (for padding).
 * @precision: Precision of the output (not used for hexadecimal integer).
 * @size: The size of the integer (S_LONG, S_SHORT).
 *
 * Return: Number of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int a;
	int r = write_num(0, n, buffer, flags, width, precision, _strlen(map_to));
	int map_len = _strlen(map_to);
	char original_char = buffer[i];
	int i;

	if (size == S_LONG)
		a = va_arg(types, unsigned long int);
	else if (size == S_SHORT)
		a = (unsigned short)va_arg(types, unsigned int);
	else
		a = va_arg(types, unsigned int);

	if (r > 0 && flag_ch != 0)
		r += handle_write_char(flag_ch, buffer, 0, 0, 0, 0);

	if (r > 0)
	{
		for (i = r - 1; i >= 0; i--)
		{
			if (original_char >= 0 && original_char < map_len)
			buffer[i] = map_to[original_char];
		}
	}

	return (r);
}
