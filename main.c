#include "shell.h"

/**
 * prompt_user - Displays prompt if shell is interactive
 */
void prompt_user(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * handle_input - Handles user input and command execution
 * @line: pointer to the input buffer
 * @nread: number of characters read
 * @exit_status: pointer to exit status variable
 * Return: -1 to exit shell, 0 to continue
 */
int handle_input(char *line, ssize_t nread, int *exit_status)
{
	char **args;

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	args = parse_line(line);
	if (args == NULL)
		return (0);

	if (_strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		return (-1);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	else
	{
		execute_command(args, "./hsh", exit_status);
	}
	free_args(args);
	return (0);
}

/**
 * main - Entry point for the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int exit_status = 0;
	int status;

	while (1)
	{
		prompt_user();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		status = handle_input(line, nread, &exit_status);
		if (status == -1)
			break;
	}

	free(line);
	return (exit_status);
}

