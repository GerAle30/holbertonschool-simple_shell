#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_environment - prints the current environment variables
 */
void print_environment(void)
{
	size_t i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}

int handle_command(char **args, char *line, const char *prog_name,
		   int *should_exit, int current_status)
{
	int exit_status = current_status;

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		free(line);
		*should_exit = 1;
		return (exit_status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
		free_args(args);
		free(line);
		return (0);
	}

	execute_command(args, prog_name, &exit_status);
	free_args(args);
	free(line);
	return (exit_status);
}

