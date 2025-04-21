#include "shell.h"

/**
 * parse_line - Split input line into an array of arguments
 * @line: Input string to parse
 *
 * Return: NULL-terminated array of strings (arguments)
 */
char **parse_line(char *line)
{
	char *token = NULL, *line_copy = NULL;
	char **args = NULL;
	int i = 0, bufsize = 64;

	args = malloc(sizeof(char *) * bufsize);
	if (args == NULL)
		return (NULL);

	line_copy = strdup(line);
	token = strtok(line_copy, " \t\r\n");

	while (token != NULL)
	{
		args[i++] = strdup(token);
		if (i >= bufsize)
		{
			bufsize += 64;
			args = realloc(args, sizeof(char *) * bufsize);
			if (args == NULL)
			{
				free(line_copy);
				return (NULL);
			}
		}
		token = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;
	free(line_copy);
	return (args);
}

