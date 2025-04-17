#include "shell.h"

int shell_exit(char **args, char *shell_name, int line_num)
{
	int status = 0;
	(void)shell_name;
	(void)line_num;

	if (args[1])
		status = atoi(args[1]);
	exit(status);
}

int shell_env(char **args)
{
	char **env;
	(void)args;

	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return 0;
}

int shell_cd(char **args, char *shell_name, int line_num)
{
	/* CD implementation */
	return 0;
}
