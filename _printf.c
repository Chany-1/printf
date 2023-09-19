#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            count++;
        }
        else
        {
            i++; // Move past the '%'

	     switch (format[i])
            {
                case 'c':
                {
                    unsigned char c = (unsigned char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    if (s == NULL)
                        s = "(null)";
                    int len = strlen(s);
                    write(1, s, len);
                    count += len;
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }


