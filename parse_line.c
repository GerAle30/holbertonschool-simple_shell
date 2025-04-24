#include "shell.h"

/**
 * parse_line - Divides a line into tokens (command + arguments)
 * @line: line to parse
 * Return: array of tokens (arguments)
 */
char **parse_line(char *line)
{
	char **args;
	char *token;
	int bufsize = 64, position = 0;

	args = malloc(bufsize * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		args[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	args[position] = NULL;

	return (args);
}

