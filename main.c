#include "main.h"
/**
 */
int main(int ac, char **av, char **env)
{
	char *command;
	size_t n = 100;
	ssize_t read_size;
	pid_t pid;
	char *args[32];
	char *token;
	int arg_count = 0, i = 0;

	command = (char *)malloc(sizeof(char) * n);

	if (command == NULL)
	{
		perror("Memory allocation error");
		return (1);
	}
	while (1)
	{
		arg_count = 0;
		printf("$ ");
		read_size = getline(&command, &n, stdin);
		if (read_size == -1)
		{
			if (feof(stdin))
				break;
			else
			{
				perror("Error reading input");
				continue;
			}
		}
		if (command[read_size - 1] == '\n')
			command[read_size - 1] = '\0';

		token = strtok(command, " ");
		while (token != NULL && arg_count < 32)
		{
			args[arg_count] = token;
			token = strtok(NULL, " ");
			arg_count++;
		}
		args[arg_count] = NULL;
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("Fork error");
			continue;
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("Command not found");
				exit(1);
			}
		}
		else
			wait(NULL);
	}
	free(command);
	return (0);
}

