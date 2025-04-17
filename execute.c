#include "shell.h"

int execute_command(char **args, char *shell_name, int line_num)
{
	pid_t pid;
	char *path;
	int status;

	if (!args || !args[0])
		return (1);

	/* Handle builtins with all required arguments */
	if (handle_builtins(args, shell_name, line_num) == 0)
		return (0);

	/* Handle external commands */
	path = find_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				shell_name, line_num, args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(path, args, environ) == -1)
		{
			perror(shell_name);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		free(path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (1);
	}
	else
	{
		/* Fork failed */
		perror("fork");
		free(path);
		return (1);
	}
}
