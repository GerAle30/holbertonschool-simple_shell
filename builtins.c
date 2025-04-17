#include "shell.h"

int handle_builtins(char **args, char *shell_name, int line_num)
{
	if (!args[0])
		return (-1);

	if (_strcmp(args[0], "exit") == 0)
		return shell_exit(args, shell_name, line_num);

	if (_strcmp(args[0], "env") == 0)
	{
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
}
