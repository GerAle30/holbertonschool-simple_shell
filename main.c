#include "shell.h"

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	int status = 0;
	int line_number = 1;
	int is_terminal = isatty(STDIN_FILENO);

	(void)argc;

	while (1) {
		if (is_terminal)
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			break;

		char **args = parse_input(line);
		if (args[0]) {
			status = execute_command(args, argv[0], line_number);
			if (!is_terminal)
				line_number++;
		}
		free(args);
	}

	free(line);
	return (status);
}
