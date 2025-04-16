#include "shell.h"

/**
 * shell_exit - Handles 'exit' command
 * @args: Command arguments
 * @shell_name: For error messages
 * @line_number: For error messages
 * Return: Exit code
 */
int shell_exit(char **args, char *shell_name, int line_number)
{
	int status = exit_status;

	if (args[1])
	{
		char *end;
		long num = strtol(args[1], &end, 10);

		if (*end != '\0')
		{
			fprintf(stderr, "%s: %d: exit: numeric argument required\n",
					shell_name, line_number);
			exit(2);
		}
		status = (int)num;
	}

	exit(status);
}

/**
 * shell_env - Prints environment variables
 * @args: Unused
 * Return: Always 0
 */
int shell_env(char **args)
{
	(void)args;
	for (char **env = environ; *env; env++)
		printf("%s\n", *env);
	return (0);
}
