/**
*write_number - Writes a formatted number to the buffer
*@is_positive: Flag indicating if the number is positive
*@ind: Index where writing should start
*@buffer: Buffer where the output is stored
*@flags: Formatting flags
*@width: Minimum width of the output
*@precision: Minimum number of characters to be printed
*@size: Size modifier (e.g., S_LONG, S_SHORT)
*Return: Number of characters written
*/
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int count = ind;
	char padd = (flags & F_ZERO && !(flags & F_MINUS)) ? '0' : ' ';

	if (!is_positive && (flags & F_ZERO) && (flags & F_MINUS))
	{
		buffer[count++] = '-';
	}

	while (width > 0 && width-- > precision)
	{
		buffer[count++] = padd;
	}

	if (!is_positive && !(flags & F_ZERO) && !(flags & F_MINUS))
	{
		buffer[count++] = '-';
	}

	while (precision > 0 && precision-- > ind - count)
	{
		buffer[count++] = '0';
	}

	return (count);
}
