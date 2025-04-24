#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point for the shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (argv[0] is program name)
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int exit_status = 0;
	int interactive;
	int should_exit = 0;
	(void)argc;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			print_prompt();

		line = read_line();
		if (!line)
			break;

		trim_newline(line);

		if (is_blank(line))
		{
			free(line);
			continue;
		}

		args = split_line(line);
		if (!args || !args[0])
		{
			free_args(args);
			free(line);
			continue;
		}

		exit_status = handle_command(args, line, argv[0], &should_exit, exit_status);

		if (should_exit)
			exit(exit_status);
	}

	if (interactive)
		write(STDOUT_FILENO, "\n", 1);

	return (exit_status);
}

