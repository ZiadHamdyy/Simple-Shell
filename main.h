#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct data_s
{
	char **env;
	char *path;
	char **array_path;
	char **concated_array;
	char *command;
	int error;
} Data;
extern Data d;
int _strlen(char *s);
char *_path(char **env);
void _env(char **env);
void free_2darr(char **array_path);
char **_array_path(char *path);
char **concat_command(char **array_path, char *command);
int my_command(char **args);
int just_spaces(char *command);
void _exec(char **concat_, char **command);
void __exit(char *value);
void free_all();
#endif
