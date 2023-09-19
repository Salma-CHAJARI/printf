#include "main.h"

/**
 * get_flags - Extracts formatting flags.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * Return: extracted formatting flags.
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	int done = 0;

	while (!done)
	{
		switch (format[*i])
		{
		case '-':
		flags |= F_MINUS;
		(*i)++;
		break;
		case '+':
		flags |= F_PLUS;
		(*i)++;
		break;
		case '0':
		flags |= F_ZERO;
		(*i)++;
		break;
		case '#':
		flags |= F_HASH;
		(*i)++;
		break;
		case ' ':
		flags |= F_SPACE;
		(*i)++;
		break;
		default:
		done = 1;
		break;
		}
	}

	return (flags);
}
