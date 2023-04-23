#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string containing zero or more directives
 * Return: Number of Characters Printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c, *s;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
				break;
			case 's':
				s = va_arg(args, char*);
				while (*s)
				{
					write(1, s, 1);
					s++;
					count++;
				}
				break;
			case '%':
				write(1, format, 1);
				count++;
				break;
			default:
				va_end(args);
				return (-1);
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
