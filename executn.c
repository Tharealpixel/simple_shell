#include "main.h"

/**
 * _strcpy -copy function string
 * @dest: the string
 * @src: the string
 * @n: the amout to be copy
 * Return: the string
 */
char *_strcpy(char *dest, char *src, int n)
{
	int j, v;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && i < n - 1)
	{
		dest[j] = src[v];
		j++;
	}
	if (j < n)
	{
		v = j;
		while (v < n)
		{
			dest[v] = '\0';
			v++;
		}
	}
	return (s);
}

/**
 * _strcat -concatenat function two strings
 * @dest: the 1st string
 * @src: 2nd string
 * @n: amount of bytes
 * Return: the string
 */
char *_strcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr -locates a function a character in a string
 * @s: string to be parsed
 * @c: charcter to look for
 * Return: (s) a pointer to area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
