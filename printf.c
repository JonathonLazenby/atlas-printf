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
	int count;
	char c;
	va_list args;
	char *str;

	count = 0;
	va_start(args, format);	

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			c = *format++;
			if (c == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
			else if (c == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					_puthchar("(null)");
					count += 6;
				}
				else
				{
					while(*str != '\0')
					{
						_putchar(*str++);
						count++;
					}
				}
			}
			else if (c == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(c);
				count += 2;
			}
		}
		else
		{
			_putchar(c);
			count++;
		}
	}
	va_end(args);
	return count;
}
