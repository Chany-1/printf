#ifndef MAIN_H
#define MAIN_H

#define BUFFERSIZE 1025
#include <stdarg.h>

/**
  * struct accessTypes - structure to lookup functions for access types
  * @access: flags are preceded by a '%' character.
  * @f: pointer to function
  */
typedef struct accessTypes
{
	char *access;
	char *(*f)();
} v_types;

int _printf(const char *format, ...);
char *(*access_valid_type(char s))(va_list);
char *loc_char(va_list c);
char *loc_string(va_list *s);
char *loc_percent();
char *loc_int(va_list n);
char *loc_unsigned(va_list usign);
char *loc_nothing(char);
char *loc_reverse(va_list s);
char *loc_rot13(va_list s);
char *loc_octal(va_list n);
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen);
int _strlen(char *s);
void _puts(char *buffer, int size);
int malloc_buff(char *hold, int olen, char *buffer, int bulen, double *total);
char *chartos(char c);

#endif
