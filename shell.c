#include "shell.h"

/**
 * display_prompt - Displays shell prompt
 */
void display_prompt(void)
{
<<<<<<< HEAD
	if (isatty(STDIN_FILENO))
		printf("#cisfun$");
=======
	printf("#cisfun$ ");
>>>>>>> 0f7de9f (mensaje)
	fflush(stdout);
}

/**
 * handle_builtins - Handles built-in commands
 * @args: Command arguments
 * Return: 0 if exit, 1 if other builtin executed, -1 if not a builtin
 */
int handle_builtins(char **args)
{
	if (!args || !args[0])
		return (-1);

	if (_strcmp(args[0], "exit") == 0)
	{
		return (shell_exit(args, "shell", 1));
	}

	if (_strcmp(args[0], "env") == 0)
	{
		return (shell_env(args));
	}

	if (_strcmp(args[0], "cd") == 0)
	{
		return (shell_cd(args, "shell", 1) == 0 ? 1 : 1);
	}

	return (-1);
}
/**
 * find_path - Finds command in PATH
 * @command: Command to find
 * Return: Full path if found, NULL otherwise
 */
char *find_path(const char *command)
{
	char *path, *dir, *full_path;
	struct stat st;

	if (!command)
		return (NULL);

	/* Check if command has path (/, ./) */
	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (_strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path = _strdup(path);
	dir = strtok(path, ":");
	full_path = malloc(MAX_PATH_LEN);

	while (dir)
	{
		_strcat(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &st) == 0)
		{
			free(path);
			return (full_path);
		}

		full_path[0] = '\0';
		dir = strtok(NULL, ":");
	}
	free(full_path);
	free(path);
	return (NULL);
}

