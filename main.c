#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		args = parse_line(line);
		if (args == NULL)
			continue;

		if (_strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			break;
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			print_env();
		}
		else
		{
			execute_command(args, args[0]);
		}
		free_args(args);
	}
	free(line);
	return (0);
}

