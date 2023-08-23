#include "main.h"
/**
 * _env - ..........
 * @env:array of string.
 * Return:void.
 */
void _env(char **env)
{
	int i = 0;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}
