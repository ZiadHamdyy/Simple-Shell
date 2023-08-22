#include "main.h"
/**
 * _strncmp - ....
 * @s1:first string.
 * @s2:second string.
 * @n:len.
 * Return:0.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
