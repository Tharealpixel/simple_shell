#include "main.h"

/**
 * inter -Return if shell is interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode
 */
int inter(inf_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * he_delimiter -checks function
 * @c: the character
 * @del: the string
 * Return: 1 if true, 0 if false
 */
int he_delimiter(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}

/**
 * _alpha -alpha checks alphabitic functions charcter
 * @c: The character
 * Return: 1 if c is alpha, 0 otherwise
 */

int _alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _str -converts a string
 * @s: string
 * Return: 0 if no number in string
 */
int _str(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}
