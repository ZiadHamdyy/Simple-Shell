#include "main.h"
#include "global.h"
/**
 * main - ........
 * @ac:argc.
 * @av:argv.
 * @env:the enviroment.
 * Return:0.
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
		char **env)
{
	char *command = NULL, *path, **array_path, **concat_ = NULL;
	size_t n = 100;
	ssize_t read_size;

	d.env = env;
	path = _path(d.env);
	array_path = _array_path(path);
	signal(SIGINT, sigint_handler);
	command = (char *)malloc(sizeof(char) * n);
	if (command == NULL)
		return (1);
	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		read_size = getline(&command, &n, stdin);
		if (read_size == -1)
		{
			if (feof(stdin))
			{
				if (isatty(0))
					write(1, "\n", 1);
				break;
			}
			else
				continue;
		}
		if (command[read_size - 1] == '\n')
			command[read_size - 1] = '\0';
		if (just_spaces(command))
			continue;
		d.path = path;
		d.array_path = array_path;
		d.command = command;
		_exec(concat_, command);
	}
	free(command);
	free(path);
	free(array_path);
	return (0);
}
/**
 * _exec - ...........
 * @concat_:array of string.
 * @line:string.
 * Return:void.
 */
void _exec(char **concat_, char *line)
{
	int i = 0, arg_count = 0;
	pid_t pid;
	char *token, *command[32];

	token = strtok(line, " ");
	while (token != NULL && arg_count < 32)
	{
		command[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	command[arg_count] = NULL;
	if (my_command(command))
		return;
	concat_ = concat_command(d.array_path, command[0]);
	d.concated_array = concat_;
	while (concat_[i])
	{
		if (access(concat_[i], X_OK) != 0)
		{
			i++;
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(concat_[i], command, d.env) == -1)
				exit(1);
		}
		else
		{
			wait(NULL);
			d.error = 0;
			free_2darr(concat_);
			return;
		}
	}
	perror("Command not found");
	d.error = 1;
	free_2darr(concat_);
}
/**
 * just_spaces - ............
 * @command:the command.
 * Return:0 or 1.
 */
int just_spaces(char *command)
{
	size_t i;

	for (i = 0; i < strlen(command); i++)
	{
		if (command[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * __exit - .........
 * @value:string.
 * Return:void.
 */
void __exit(char *value)
{
	if (!value)
		exit(d.error);
	exit(atoi(value));
}
