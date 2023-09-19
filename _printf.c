#include "main.h"
/**
*_printf - Custom printf function.
*@format: The format string.
*
*Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, printed = 0;
char buffer[BUFF_SIZE] = {0};

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;
int flags = get_flags(format, &i);
int width = get_width(format, &i, args);
int precision = get_precision(format, &i, args);
int size = get_size(format, &i);

int result = handle_print(format, &i, args, buffer,  flags, width,
precision, size);
if (result == -1)
{
va_end(args);
return (-1);
}
printed += result;
}
else
{
printed += handle_write_char(format[i], buffer, 0, 0, 0, 0);
i++;
}
}

if (buffer[0] != '\0')
{
printed += write(1, buffer, _strlen(buffer));
_memset(buffer, 0, BUFF_SIZE);
}

va_end(args);
return (printed);
}
