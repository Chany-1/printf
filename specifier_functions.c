#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
  * loc_char - converts a char to a string
  * @c: char to convert
  * Return: 2 byte string
  */
char *loc_char(va_list c)
{
	char string[2];
	char *k;

	k = string;
	string[0] = va_arg(c, int);
	string[1] = '\0';
	return (p);
}
/**
  * loc_string - passes a string through
  * @s: string to pass through
  * Return: unmodified string
  */
char *loc_string(va_list *s)
{
	char *string;

	string = va_arg(s, char *);
	if (string == NULL)
		return ("(null)");
	return (string);
}
/**
  * loc_percent - passes a % sign through
  * Return: percent sign as a character string
  */
char *loc_percent(void)
{
	char *string;

	string = "%";
	return (string);
}
/**
  * loc_int - converts integers into character arrays
  * @npoint: integer to convert from va_args
  * Return: pointer to string
  */
char *loc_int(va_list npoint)
{
	int n;
	int i, res, temp, expo, count;
	char *string;

	n = va_arg(npoint, int);
	count = i = 0;
	expo = 1;
	n >= 0 ? (res = n * -1) : (res = n, count++);
	temp = res;
	while (temp <= -10)
	{
		expo *= 10;
		temp /= 10;
		count++;
	}
	string = malloc((count + 1) * sizeof(char));
	if (n < 0)
		string[i++] = '-';
	while (expo >= 1)
	{
		string[i++] = (((res / expo) % 10) * -1 + '0');
		expo /= 10;
	}
	return (string);
}
/**
  * loc_unsigned - converts unsigned to char arrays
  * @usign: unsigned int to convert from va_args
  * Return: pointer to string
  */
char *loc_unsigned(va_list usign)
{
	unsigned int i, res, temp, expo, count;
	char *string;

	res = va_arg(usign, unsigned int);
	count = i = 0;
	expo = 1;
	temp = res;
	while (temp >= 10)
	{
		expo *= 10;
		temp /= 10;
		count++;
	}
	string = malloc((count + 1) * sizeof(char));
	while (expo >= 1)
	{
		string[i++] = (((res / expo) % 10) + '0');
		expo /= 10;
	}
	return (string);
}
