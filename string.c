#include "main.h"
/**
 * _strlen - a function that returns the length of a string.
 * @s:the length of a string.
 * Return:the length of a string.
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
		a++;
	return (a);
}
/**
 * _strcpy - copies the string pointed to by src,including
 * the terminating null byte (\0), to the buffer pointed to by dest.
 * @dest:the terminating null byte (\0).
 * @src:copies the string.
 * Return:the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings.
 * @s1:the first string.
 * @s2:the second string.
 * Return:if the two strings are equal return 0.
 * if the first string is greater then the second
 * string return a number greater then 0.
 * else return number less then 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strcat - concatenates two strings.
 * @dest:a first string.
 * @src:a second string.
 * Return:a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	for (j = 0 ; src[j] != '\0'; j++)
	{
		dest[i++] = src[j];
	}
	dest[i] = '\0';

	return (dest);
}
