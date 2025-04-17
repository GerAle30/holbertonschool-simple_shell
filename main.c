#include "shell.h"
#include <unistd.h>  /* For 'environ' */

/**
 * main - Shell entry point
 * @argc: Argument count (unused)
 * @argv: Argument list (shell name)
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	int exit_status = 0;  /* Now local */
	int line_number = 1;
	int is_terminal = isatty(STDIN_FILENO);

	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (is_terminal)
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			break;

		char **args = parse_input(line);

		if (args[0])
		{
			exit_status = execute_command(args, argv[0], line_number);
			if (!is_terminal)
				line_number++;
		}

		free(args);
	}

	free(line);
	return (exit_status);
}
