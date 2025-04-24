
#include "shell.h"

/**
 * _strlen - Calculate the length of a string
 * @s: Pointer to the string
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s && s[len])
	{
		len++;
	}

	return (len);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if equal, negative or positive if not
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/**
 * _strcpy - Copy string from src to dest
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while (*src)
	{
		*d++ = *src++;
	}

	return (dest);
}

/**
 * _strcat - Concatenate two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	return (dest);
}

/**
 * _strdup - Duplicates a string in a new memory space
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if malloc fails
 */
char *_strdup(const char *str)
{
	char *copy;
	size_t len = _strlen(str), i;

	copy = malloc(len + 1);
	if (!copy)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = '\0';

	return (copy);
}
