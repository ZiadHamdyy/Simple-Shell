#include "main.h"
/**
 * _env - ..........
 * @env:array of string.
 * Return:void.
 */
void _env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
