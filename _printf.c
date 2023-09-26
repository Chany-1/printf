#include "main.h"

/**
* _printf - Produces output according to a format
* @format: Is a character string. The format string
* is composed of zero or more directives
*
* Return: The number of characters printed (excluding
* the null byte used to end output to strings)
**/
int _printf(const char *format, ...)
{
	int size;
	va_list argz;
	if (format == NULL)
		return (-1);

	size = _strlen(format);
	if (size <= 0)
		return (0);

	va_start(argz, format);
		size = handler_function(format, args);
		_putchar(-1);
		va_end(argz);
		return (size);
}
