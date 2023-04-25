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
	int printed_chars = 0, printed = 0, ind = 0;
	int i, flags, width, precision, size;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[ind++] = format[i];
			if (ind == BUFF_SIZE)
				print_buffer(buf, &ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buf, &ind);

			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);

			++i;
			printed = handle_print(format, &i, args, buf,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);

			printed_chars += printed;
		}
	}
	print_buffer(buf, &ind);
	va_end(args);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 *
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
