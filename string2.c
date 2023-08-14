#include "main.h"
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

