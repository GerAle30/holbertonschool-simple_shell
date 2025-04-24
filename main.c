#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (used for error messages)
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args = NULL;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, " $ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(0);
		}

		args = parse_line(line);

		if (args == NULL || args[0] == NULL)
		{
			free_args(args);
			continue;
		}

		if (handle_builtin(args, line))
		{
			free_args(args);
			continue;
		}

		execute_command(args, argv[0]);

		free_args(args);
	}

	free(line);
	return (0);
}

