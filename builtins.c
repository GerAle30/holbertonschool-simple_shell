#include "shell.h"
#include <string.h>

/**
 * handle_builtin - Handle built-in shell commands
 * @args: Command and its arguments
 * @line: Input line (to free if exiting)
 *
 * Return: 1 if a built-in command was handled, 0 otherwise
 */
int handle_builtin(char **args, char *line)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}

/**
 * print_env - Print the current environment
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

