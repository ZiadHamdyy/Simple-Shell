#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
/**
 * struct data_s - struct for global variables.
 * @ac:argc.
 * @av:argv.
 * @env:the enviroment.
 * @path:a string.
 * @array_path:array of strings.
 * @concated_array:array of string.
 * @command:string.
 * @error:error.
 */
typedef struct data_s
{
	int ac;
	char **av;
	char **env;
	char *path;
	char **array_path;
	char **concated_array;
	char *command;
	int error;
} Data;
extern Data d;
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_path(char **env);
void _env(char **env);
void free_2darr(char **array_path);
char **_array_path(char *path);
char **concat_command(char **array_path, char *command);
int my_command(char **args);
int just_spaces(char *command);
void _exec(char **concat_, char *line);
void __exit(char *value);
void free_all(void);
void sigint_handler(int signal);
#endif
