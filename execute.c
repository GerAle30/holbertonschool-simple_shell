#include "shell.h"

/**
 * execute_command - Runs a command
 * @args: Command and arguments
 * @shell_name: For error messages
 * @line_number: For error messages
 * Return: Exit status
 */
int execute_command(char **args, char *shell_name, int line_number)
{
	pid_t child_pid;
	int status;

	if (!args[0])
		return (1);
	/* Empty command*/

	/* Try built-ins first*/
	if (strcmp(args[0], "exit") == 0)
		return (shell_exit(args, shell_name, line_number));

	if (strcmp(args[0], "env") == 0)
		return (shell_env(args));

	if (strcmp(args[0], "cd") == 0)
		return (shell_cd(args, shell_name, line_number));

	/* Fork to run external command*/
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Child process*/
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					shell_name, line_number, args[0]);
			exit(127);
		}
	}
	else if (child_pid < 0)
	{
		perror("fork");
		return (1);
	}
	else
	{
		/* Parent waits for child*/
		waitpid(child_pid, &status, 0);
		exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}
