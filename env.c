#include "main.h"
/**
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
