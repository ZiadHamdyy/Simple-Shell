#include "main.h"

/**
*/
int my_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		/* TODO: exit function */
		free_all();
		__exit(args[1]);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		_env(d.env);
		return (1);
	}
	return (0);
}
void free_all()
{
	if (d.path)
		free(d.path);
	//if (d.concated_array[0])
		//free(d.concated_array[0]);
	if (d.concated_array)
		free(d.concated_array);
	if (d.command)
		free(d.command);
	if (d.array_path)
		free(d.array_path);
}
