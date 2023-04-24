#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string containing zero or more directives
 *
 * Return: Number of Characters Printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i;
	char *str_arg, *p, buf[1024];

	va_start(args, format);

	for (p = (char *)format; *p != '\0'; p++)
	{
		if (*p != '%')
			write(1, p, 1), printed_chars++;
		else
		{
			switch (*++p)
			{
				case 'c':
					i = va_arg(args, int), buf[0] = i;
					write(1, buf, 1), printed_chars++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					for (i = 0; str_arg[i] != '\0'; i++)
					{
						buf[i] = str_arg[i];
					}
					write(1, buf, i), printed_chars += i;
					break;
				case '%':
					buf[0] = '%', write(1, buf, 1), printed_chars++;
					break;
				default:
					buf[0] = '%', buf[1] = *p;
					write(1, buf, 2), printed_chars += 2;
					break;
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
