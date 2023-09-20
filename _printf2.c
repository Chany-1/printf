#include <stdio.h>
#include <stdarg.h>

int_printf(const char *format, ...){
	va_list args;
	va_start(args, format);

	int char_count = 0;

	while(*format){
	if (*format != '%'){
		putchar(*format++);
		char_count++;
	} else if(*(++format) == 'c'){
		char c = va_arg(args, int);
		putchar(c);
		char_count++;
		format++;
	}else if (*format == 's'){
		char *str = va_arg(args, char*);
	while (*str){
			putchar(*str++);
			char_count++;
			format++;
		}
	}else{
			putchar('%');
			putchar(*format++);
			char_count += 2;
		}
	}
	va_end(args);
	return char_count;
}

int main() {
	char c = 'A';
	char *str = "Hello, world!";
	int count = printf("Character: %c, String: %s, Percentage: %%\n", c, str);
	printf("Total characters printed: %d\n", count);
		return 0;
    }
