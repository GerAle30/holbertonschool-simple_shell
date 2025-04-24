#include "shell.h"

/**
 * _strncmp - Compares two strings up to n bytes
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to compare
 * Return: 0 if equal, difference otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (0);
}

