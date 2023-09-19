#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0, i = 0;
    while (format[i])
    {
        if (format[i] != '%')
            putchar(format[i]), count++;
        else
        {
            i++;
            switch (format[i])
            {
                case 'c': putchar(va_arg(args, int)), count++; break;
                case 's':
                {
                    char *s = va_arg(args, char *);
                    s = s ? s : "(null)";
                    count += write(1, s, strlen(s));
                    break;
                }
                case '%': putchar('%'), count++; break;
                default: putchar(format[i]), count++; break;
            }
        }
        i++;
    }
    va_end(args);
    return count;
}

int main(void)

{
   int len1 = printf("prog lang: %c\n", 'c');
   int len2 = _printf("prog lang: %c\n", 's');
   int len3 = _printf("prog lang: %c\n", '%%');

   const char *str = "Hello, World!";
   len1 += printf("String: %s\n", str);
   len2 += _printf("String: %s\n", str);
   len3 += _printf("String: %s\n", str);

   printf("Length 1: %d, Length 2: %d, Length 3: %d\n", len1, len2, len3);

   return 0;
}

