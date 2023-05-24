#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 * Return: On success, the number of characters written.
 *         On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to the standard output
 * @str: The string to be printed
 * @str: The string to be printed.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
