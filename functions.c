#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
* access_valid_type - ID the type specifier passed by printf with a valid_type
* @s: Type to check given as char
* Return: pointer function of char type, valid_type matched
**/
char *(*access_valid_type(char s))(va_list)
{
		int i;
			v_types valid_types[] = {
			{"c", found_char},
			{"s", found_string},
			{"%", found_percent},
			{"d", found_int},
			{"i", found_int},
			{"u", found_unsigned},
			{"o", found_octal},
			{"r", found_reverse},
			{"R", found_rot13},
			{NULL, NULL}
			};

	for (i = 0; valid_types[i].valid; i++)
	{

		if (s == *valid_types[i].valid)
		{
			return (valid_types[i].f);
		}
	}

	return (NULL);
}
/**
* malloc_buffer - allocates characters to buffer, handling overflows
* @hold: string to allocate into buffer
* @holdlen: hold length
* @buffer: buffer char array
* @buflen: pointer to end of buffer
* @total: pointer to total character counter
* Return: buffer length
**/
int malloc_buffer(char *hold, int holdlen, char *buffer, int buflen, double *total)
{
	int sizecpy = 0;

	if (holdlen + buflen > BUFSIZE)
	{
	sizecpy = BUFSIZE - buflen;
	_memcpy(buffer, hold, sizecpy, buflen);
	_puts(buffer, BUFFSIZE);
	hold += sizecpy;
	_memcpy(buffer, hold, holdlen - sizecpy, 0);
	buflen = holdlen - sizecpy;
	*total += BUFFSIZE;
	}
	else
	{
	_memcpy(buffer, hold, holdlen, buflen);
	buflen += holdlen;
												}
	return (buflen);
}
/**
* chartos - converts a character to a string
* @c: character to convert
* Return: pointer to string
**/
char *chartos(char c)
{
	char string[1];
	char *p;

	p = string;
	string[0] = c;
	return (p);
}
/**
* loc_nothing - no matches found but % passed
* @c: character unmatched to return and store
* Return: string with percent and character.
**/
char *loc_nothing(char c)
{
	char string[3];
	char *p;

	p = string;
	string[0] = '%';
	string[1] = c;
	string[2] = '\0';
	return (p);
}
