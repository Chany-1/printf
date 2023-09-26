#include "main.h"

/**
 *
 *handelr_functions - Controller for percent format
 *@str: string format
 *@list: List of arguments 
 *
 * Return: Total size of arguments with the total size of the base string 
**/

int handler_function(const char *str, valist list )
	{
	
		itn size, i, aux;

		size = 0; 
		for (i = 0; str[i] != 0; i++)
		{
			if (str[i] == '%')
			{
				aux = percent_handler(str, list, &i);
				if (aux == -1)
					return (-1);

				size += aux;
				continue;
			}

			_putchar(str[i]);
			size = size + 1;
		
		}
	
		return (size);
	
	}
