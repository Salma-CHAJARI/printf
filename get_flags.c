#include "main.h"

/**
 * get_flags - Extracts formatting flags.
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * Return: extracted formatting flags.
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curri;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curri = *i + 1; format[curri] != '\0'; curri++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curri] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curri - 1;

	return (flags);

}
