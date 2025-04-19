#include "shell.h"

 HEAD
int handle_builtins(char **args, char *shell_name, int line_num)
{
	if (!args[0])
		return (-1);

/**
 * shell_cd - Change directory command implementation
 * @args: Command arguments
 * @shell_name: Shell name for error messages
 * @line_num: Line number for error messages
 * Return: 0 on success, 1 on failure
 */
int shell_cd(char **args, char *shell_name, int line_num)
{
	char *dir = args[1] ? args[1] : getenv("HOME");

	if (!dir)
	{
		fprintf(stderr, "%s: %d: cd: HOME not set\n", shell_name, line_num);
		return (1);
	}

	if (chdir(dir) == -1)
	{
		fprintf(stderr, "%s: %d: cd: can't cd to %s\n",
				shell_name, line_num, dir);
		return (1);
	}
	return (0);
}

/**
 * shell_exit - Exit command implementation
 * @args: Command arguments
 * @shell_name: Shell name for error messages
 * @line_num: Line number for error messages
 * Return: Exit status
 */
int shell_exit(char **args, char *shell_name, int line_num)
{
	int status = 0;
 0f7de9f (mensaje)

	if (_strcmp(args[0], "exit") == 0)
		return shell_exit(args, shell_name, line_num);

	if (_strcmp(args[0], "env") == 0)
	{
 HEAD
		char **env = environ;
		while (*env)
			printf("%s\n", *env++);
		return (1);
	}

	if (_strcmp(args[0], "cd") == 0)
		return shell_cd(args, shell_name, line_num);

	return (-1);
}

int shell_exit(char **args, char *shell_name, int line_num)
{
	(void)shell_name;
	(void)line_num;
	exit(args[1] ? atoi(args[1]) : 0);
}

int shell_cd(char **args, char *shell_name, int line_num)
{
	char *dir = args[1] ? args[1] : getenv("HOME");

	if (!dir)
	{
		fprintf(stderr, "%s: %d: cd: HOME not set\n", shell_name, line_num);
		return (1);
	}

	if (chdir(dir) == -1)
	{
		fprintf(stderr, "%s: %d: cd: can't cd to %s\n", shell_name, line_num, dir);
		return (1);
	}
	return (0);

		char *endptr;

		status = strtol(args[1], &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n",
					shell_name, line_num, args[1]);
			return (1);
		}
	}
	exit(status);
}

/**
 * shell_env - Print environment variables
 * @args: Command arguments
 * Return: Always 1 (success)
 */
int shell_env(char **args)
{
	char **env = environ;
	(void)args;

	while (*env)
		printf("%s\n", *env++);

	return (1);
 0f7de9f (mensaje)
}
