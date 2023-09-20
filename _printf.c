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

<<<<<<< HEAD
	   
=======
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
		 default:
                {
                    char chany[2] = {format[i], '\0'};
                    write(1, chany, 1);
                    count++;
                    break;
                }
            }
        }
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

>>>>>>> cd518e6c23a8a420b433bdf0c073ef881129c968
