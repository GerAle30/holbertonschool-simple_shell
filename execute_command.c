#include "shell.h"

/**
 * find_path - Find the PATH variable in environ
 * Return: pointer to the PATH string or NULL
 */
char *find_path(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5); /* Skip "PATH=" */
	}
	return (NULL);
}

/**
 * execute_command - Executes a command if it exists in PATH
 * @args: Command and arguments
 * @prog: Program name (for error messages)
 * @exit_status: Pointer to variable that stores exit status
 */
void execute_command(char **args, char *prog, int *exit_status)
{
	char *cmd = NULL, *path, *pcopy, *tok;
	char full_path[PATH_MAX];
	pid_t pid;
	int status;

	if (access(args[0], X_OK) == 0)
	{
		cmd = args[0];
	}
	else
	{
		path = find_path();
		if (path)
		{
			pcopy = _strdup(path);
			tok = strtok(pcopy, ":");
			while (tok)
			{
				snprintf(full_path, sizeof(full_path), "%s/%s", tok, args[0]);
				if (access(full_path, X_OK) == 0)
				{
					cmd = _strdup(full_path);
					break;
				}
				tok = strtok(NULL, ":");
			}
			free(pcopy);
		}
	}

	if (!cmd)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog, args[0]);
		*exit_status = 127;
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			*exit_status = WEXITSTATUS(status);
		else
			*exit_status = 1;
	}

	if (cmd != args[0])
		free(cmd);
}

