#include "shell.h"

/**
 * execute_command - Creates a child process to execute a command
 * @args: NULL-terminated array of arguments
 * @program_name: Name of the shell program (for error messages)
 */
void execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;
	char buffer[PATH_MAX];

	if (access(args[0], X_OK) == -1)
	{
		/* Try to resolve using PATH manually (no getenv) */
		char *path = "/bin:/usr/bin:/usr/local/bin";
		char *token = strtok(path, ":");

		while (token)
		{
			snprintf(buffer, sizeof(buffer), "%s/%s", token, args[0]);
			if (access(buffer, X_OK) == 0)
			{
				args[0] = buffer;
				break;
			}
			token = strtok(NULL, ":");
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror(program_name);
		return;
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(program_name);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

