#include "shell.h"

/**
 * _strlen - Calculates string length
 * @s: Input string
 * Return: Length of string
 */
int _strlen(const char *s)
{
    int len = 0;
    while (s && s[len])
        len++;
    return len;
}

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 * Return: Pointer to new string
 */
char *_strdup(const char *str)
{
    char *new;
    int len, i;

    if (!str)
        return NULL;

    len = _strlen(str);
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return NULL;

    for (i = 0; i <= len; i++)
        new[i] = str[i];

    return new;
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to destination string
 */
char *_strcat(char *dest, const char *src)
{
    int i, j;

    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';

    return dest;
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference between strings
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
