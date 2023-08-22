#include "main.h"
/**
 * _getline - get the line from user.
 * @lineptr:array of string.
 * @n:lenght of the strnig.
 * @stream:file.
 * Return:number of byte or -1 if failed.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity = *n;
	char *line = *lineptr;
	int c;
	size_t i = 0;
	char *new_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (line == NULL || capacity < 2)
	{
		capacity = 128;
		line = (char *)malloc(capacity);
		if (line == NULL)
			return (-1);
		*lineptr = line;
		*n = capacity;
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= capacity - 1)
		{
			capacity *= 2;
			new_line = (char *)realloc(line, capacity);
			if (new_line == NULL)
				return (-1);
			line = new_line;
			*lineptr = line;
			*n = capacity;
		}
		line[i++] = (char)c;
		if (c == '\n')
			break;
	}
	if (i == 0 && c == EOF)
		return (-1);
	line[i] = '\0';
	return (i);
}
