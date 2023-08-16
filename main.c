#include "main.h"
Data d = {NULL, NULL, NULL, NULL,NULL, 0};
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
	d.env = env;
	char *path = _path(d.env);
	char **array_path = _array_path(path);
	char **concat_;


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
			{
				printf("\n");
				break;
			}
			else
			{
				perror("Error reading input");
				continue;
			}
		}
		if (command[read_size - 1] == '\n')
			command[read_size - 1] = '\0';
		if (just_spaces(command))
			continue;

		token = strtok(command, " ");
		while (token != NULL && arg_count < 32)
		{
			args[arg_count] = token;
			token = strtok(NULL, " ");
			arg_count++;
		}
		args[arg_count] = NULL;
		
		if (my_command(args))
			continue;
		concat_ = concat_command(array_path, args[0]);
		d.path = path;
		d.array_path = array_path;
		d.concated_array = concat_;
		d.command = command;
		_exec(concat_, args);
		/*pid_t pid = fork();
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
			wait(NULL);*/
		free_2darr(concat_);
	}
	free(command);
	free(path);
	free(array_path);
	return (0);
}
void _exec(char **concat_, char **command)
{
	int i = 0;
	while (concat_[i])
	{
		if (access(concat_[i], X_OK) != 0)
		{
			i++;
			continue;
		}
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("Fork error");
			continue;
		}
		else if (pid == 0)
		{
			if (execve(concat_[i], command, d.env) == -1)
			{
				
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			d.error = 0;
			return;
		}
	}
	/* command not found */
	perror("Command not found");
	d.error = 1;
}
int just_spaces(char *command)
{
	for (size_t i = 0; i < strlen(command); i++)
	{
		if (command[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
void __exit(char *value)
{
	if (!value)
		exit(d.error);
	exit(atoi(value));
}
