/**
*handle_write_char - Handles writing a character to buffer
*@c: Character to be written
*@buffer: Buffer where the output is stored
*@flags: Formatting flags
*@width: Minimum width of the output
*@precision: Minimum number of characters to be printed
*@size: Size modifier (e.g., S_LONG, S_SHORT)
*Return: Number of characters written
*/
int handle_write_char(char c, char buffer[], int flags,
	int width, int precision, int size)
{
	int count = 0;

	if (flags & F_MINUS)
	{
		buffer[count++] = c;
	}

	while (width > 1)
	{
		buffer[count++] = c;
		width--;
	}

	if (!(flags & F_MINUS))
	{
		buffer[count++] = c;
	}

	return (count);

}

