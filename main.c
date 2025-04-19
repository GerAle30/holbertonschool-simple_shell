#include "shell.h"

<<<<<<< HEAD
=======
/**
 * main - Simple shell entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Exit status
 */
>>>>>>> 0f7de9f (mensaje)
int main(int argc, char **argv)
{
	char input[MAX_INPUT];
	char **args;
	ssize_t read_size;
	int status = 1;
<<<<<<< HEAD
	int line_number = 1;

	(void)argc;

	while (status)
	{
		display_prompt();

		read_size = read(STDIN_FILENO, input, MAX_INPUT);
=======
	int is_terminal = isatty(STDIN_FILENO);
	int line_num = 1;
	(void)argc;

	while (status)
	{
		if (is_terminal)
			display_prompt();

		read_size = read(STDIN_FILENO, input, MAX_INPUT - 1);
>>>>>>> 0f7de9f (mensaje)
		if (read_size == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
		{
<<<<<<< HEAD
			if (isatty(STDIN_FILENO))
=======
			if (is_terminal)
>>>>>>> 0f7de9f (mensaje)
				printf("\n");
			break;
		}

		input[read_size] = '\0';
		if (_strlen(input) == 0)
			continue;

		args = parse_input(input);
<<<<<<< HEAD
		status = execute_command(args, argv[0], line_number);
		if (!isatty(STDIN_FILENO))
			line_number++;
=======
		if (args[0])
		{
			status = execute_command(args, argv[0], line_num);
			line_num++;
		}
>>>>>>> 0f7de9f (mensaje)
		free(args);
	}

	return (EXIT_SUCCESS);
}

