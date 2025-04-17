#include "shell.h"

int main(int argc, char **argv)
{
	char input[MAX_INPUT];
	char **args;
	ssize_t read_size;
	int status = 1;
	int line_number = 1;

	(void)argc;

	while (status)
	{
		display_prompt();

		read_size = read(STDIN_FILENO, input, MAX_INPUT);
		if (read_size == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		input[read_size] = '\0';
		if (_strlen(input) == 0)
			continue;

		args = parse_input(input);
		status = execute_command(args, argv[0], line_number);
		if (!isatty(STDIN_FILENO))
			line_number++;
		free(args);
	}

	return (EXIT_SUCCESS);
}
