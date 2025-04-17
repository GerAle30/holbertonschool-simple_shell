#include "shell.h"

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	int exit_status = 0;
	int line_number = 1;
	int is_terminal;
	char **args;

	(void)argc; /* Mark unused parameter */
	is_terminal = isatty(STDIN_FILENO);
	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (is_terminal)
		{
			printf("$ ");
			fflush(stdout);
		}

		if (getline(&line, &len, stdin) == -1)
			break;

		args = parse_input(line);
		if (args[0])
		{
			exit_status = execute_command(args, argv[0], line_number);
			if (!is_terminal)
				line_number++;
		}
		free(args);
	}

	free(line);
	return exit_status;
}
