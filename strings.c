#include "main.h"

/**
 * _strlen - returns length of a string
 * @str: the string
 *
 * Return: length of the string
 */

unsigned int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copies a string to a destination
 * @dest: destination
 * @source: source
 *
 * Return: a pointer to string
 */

char *_strcpy(char *dest, const char *source)
{
	char *result = dest;

	while ((*dest++ = *source++))
		;
	return (result);
}

/**
 * _strcmp - compares string
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between two ascii valuves
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		if (s1[i] == '\0' || s2[i] == '\0')
			break;

		i++;
	}

	return (0);
}
