#include "shell.h"

/**
 * execute_command - Forks and executes a command
 * @args: Arguments array
 * @program_name: Name of the program (for error messages)
 */
void execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;
	char *full_path;

	full_path = args[0];
	if (access(full_path, X_OK) != 0)
	{
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(program_name);
			exit(errno == ENOENT ? 127 : 126);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		/* Check if child exited normally */
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));  /* <- Esto es clave */
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

