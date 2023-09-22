#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
* _printf - Creation of the printf function.
* @format: string passed with containg content to print.
* Return: The valuel of format.
**/
int _printf(const char *format, ...)
{

	int i, bufflen, holdlen;
	double total_buffer;
	double *total;
	va_list argk;
	char buffer[BUFFSIZE], *holder;
	char *(*pointer_get_valid)(va_list);

	for (i = 0; i < BUFFSIZE; i++)
	{
		buffer[i] = 0;
	}
	full_buffer = 0;
	obtain_valid_pointer = NULL;
	total = &full_buffer;
	va_start(argk, format);
	for (i = bufflen = holdlen = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			obtain_valid_pointer = access_valid_type(format[i + 1]);
			holder = (obtain_valid_pointer == NULL) ?
			loc_nothing(format[i + 1]) :
			obtain_valid_pointer(argk);
			holdlen = _strlen(holder);
			bufflen = malloc_buffer(holder, holdlen, buffer, bufflen, total);
			i++;
		}
		else
		{
			holder = chartos(format[i]);
			buflen = malloc_buffer(holder, 1, buffer, buflen, total);
		}
	}
	va_end(argk);
	_puts(buffer, buflen);
	return (full_buffer + buflen);
}


