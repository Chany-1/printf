#include <stdio.h>
#include <stdarg.h>

<<<<<<< HEAD
int _printf(const char *format, ...)
{ 
  va_list args;
  va_start(args, format);

 int char_count = 0;

 while (*format)
	{
 	if (*format != '%')
	{
	putchar(*format++);
	char_count++;
=======
int_printf(const char *format, ...) {

	va_list args;
	va_start(args, format);
	int char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format++);
			char_count++;
		} else if (*(++format) == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				char_count++;
				format++;
			} else if (*format == 's')
				char *str = va_arg(args, char*);

			while (*str)
			{
				putchar(*str++);
				char_count++;
				format++;
			}
	else
		{
			putchar('%');
			putchar(*format++);
			char_count += 2;
		}
>>>>>>> f3e359dba699bca17596493ad5f60da6f97dc1e5
	}
 else if (*(++format) == 'c')
	{
	char c = va_arg(args, int);
	putchar(c);
	char_count++;
	format++;
	}
 else if (*format == 's')
 {
	char *str = va_arg(args, char*);
	while (*str)
 }
	{
	putchar(*str++);
	char_count++;
	format++;
	}
 } else{
	putchar('%');
	putchar(*format++);
	char_count += 2;
  }
}
	va_end(args);
	return (char_count);
}

int main(void)
{
	char c = 'A';
	char *str = "Hello, world!";
	int count = printf("Character: %c, String: %s, Percentage: %%\n", c, str);

	printf("Total characters printed: %d\n", count);
<<<<<<< HEAD
		return 0;
=======
		return (0);
>>>>>>> f3e359dba699bca17596493ad5f60da6f97dc1e5
}