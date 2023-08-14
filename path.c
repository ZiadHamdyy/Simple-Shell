#include "main.h"
/**
 */
void _path(char **env)
{
	int i = 0;
	while (env[i] != NULL)
		printf("%s", env[i++]);
}
