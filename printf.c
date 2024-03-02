#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * 
 * 
 *
 *
 * 
 */

#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);
	while(*format)	
	{
		if(*format == '%')
		{
			format++;

			if(*format == 'c')
			{
				c = (char) va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if(*format == 's')
			{
				str = va_arg(args, char*);
				while(*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if(*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{

			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
