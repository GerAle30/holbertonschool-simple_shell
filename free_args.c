#include "shell.h"

/**
 * free_args - Free memory allocated for the argument array
 * @args: Array of strings to free
 */
void free_args(char **args)
{
	int i = 0;

	if (args == NULL)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

