#include "shell.h"

/**
 * execute_command - Executes a command with fork and execve
 * @args: Command and arguments
 * @prog: Program name (for error messages)
 */
void execute_command(char **args, char *prog)
{
	char *cmd = NULL, *p, *pcopy, *tok, path[PATH_MAX];
	pid_t pid;
	int status;

	if (access(args[0], X_OK) == 0)
		cmd = args[0];
	else
	{
		p = getenv("PATH");
		if (p)
		{
			pcopy = strdup(p);
			tok = strtok(pcopy, ":");
			while (tok && !cmd)
			{
				snprintf(path, PATH_MAX, "%s/%s", tok, args[0]);
				if (access(path, X_OK) == 0)
					cmd = strdup(path);
				tok = strtok(NULL, ":");
			}
			free(pcopy);
		}
	}
	if (!cmd)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog, args[0]);
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
		waitpid(pid, &status, 0);
	if (cmd != args[0])
		free(cmd);
}
