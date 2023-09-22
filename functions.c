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
			{"c", loc_char},
			{"s", loc_string},
			{"%", loc_percent},
			{"d", loc_int},
			{"i", loc_int},
			{"u", loc_unsigned},
			{"o", loc_octal},
			{"r", loc_reverse},
			{"R", loc_rot13},
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
* malloc_buff - allocates characters to buffer, handling overflows
* @hold: string to allocate into buffer
* @olen: hold length
* @buffer: buffer char array
* @bulen: pointer to end of buffer
* @total: pointer to total character counter
* Return: buffer length
**/
int malloc_buff(char *hold, int olen, char *buffer, int bulen, double *total)
{
	int sizecpy = 0;

	if (olen + bulen > BUFFSIZE)
	{
	sizecpy = BUFFSIZE - buflen;
	_memcpy(buffer, hold, sizecpy, buflen);
	_puts(buffer, BUFFSIZE);
	hold += sizecpy;
	_memcpy(buffer, hold, olen - sizecpy, 0);
	buflen = olen - sizecpy;
	*total += BUFFSIZE;
	}
	else
	{
	_memcpy(buffer, hold, olen, bulen);
	bulen += holdlen;
												}
	return (bulen);
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
