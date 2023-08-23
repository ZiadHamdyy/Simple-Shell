#include "main.h"
/**
 * my_command - ....
 * @args: array of string.
 * Return:1 or 0.
*/
int my_command(char **args)
{
	int value = args[1] ? atoi(args[1]) : d.error;

	if (strcmp(args[0], "exit") == 0)
	{
		free_all();
		__exit(value);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		_env(d.env);
		return (1);
	}
	return (0);
}
/**
 * free_all - .....
 * Return:void.
 */
void free_all(void)
{
	if (d.path)
		free(d.path);
	if (d.command)
		free(d.command);
	if (d.array_path)
		free(d.array_path);
}
