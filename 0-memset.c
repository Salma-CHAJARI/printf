#include "main.h"

/**
  * _memset - Fills memory with a constant byte b
  * @s: Char address to be filled
  * @b: Byte to fill
  * @n: number of interger times to fill
  * Return: Pointer to the memory area s
  */
char *_memset(char *s, char b, unsigned int n)
{
	size_t i;

	for (i = 0; i < n; i++)
		((char *)s)[i] = (char)b;
	return (s);
}
