#include "main.h"
/**
 * _strspn - Calculates the length of the initial segment of a string
 *            consisting of only characters in a given set.
 * @str: The string to search.
 * @charset: The set of characters to match.
 *
 * Return: The length of the segment as an int.
 */
int _strspn(const char *str, const char *charset)
{
	int count = 0;
	const char *p;

	while (*str)
	{
		p = charset;
		while (*p)
		{
			if (*str == *p)
			{
				count++;
				break;
			}
			p++;
		}

		if (*p == '\0')
			break;

		str++;
	}

	return count;
}
/**
 * _strlen - find the length of a string
 * @s: string
 * Return: number of bytes
 **/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp - a function that compares two strings
 *
 * @s1: string 1 input to compare
 * @s2: against this other string 2
 *
 * Return: 0 if s1 and s2 are equal
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
