#include "shell.h"

 HEAD
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

/**
 * execute_command - Execute a shell command
 * @args: Array of command arguments
 * @shell_name: Name of the shell for error messages
 * @line_num: Current line number for error messages
 * Return: Exit status of the command
 */
int execute_command(char **args, char *shell_name, int line_num)
{
	pid_t pid;
	int status;

	if (!args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (shell_exit(args, shell_name, line_num));
	if (strcmp(args[0], "env") == 0)
		return (shell_env(args));
	if (strcmp(args[0], "cd") == 0)
		return (shell_cd(args, shell_name, line_num));

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					shell_name, line_num, args[0]);
 0f7de9f (mensaje)
			exit(EXIT_FAILURE);
		}
		return (0);  /* Unreachable but satisfies compiler */
	}
 HEAD
	else if (pid > 0)
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		free(path);


	if (pid > 0)
	{
		waitpid(pid, &status, 0);
 0f7de9f (mensaje)
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (1);
	}
 HEAD
	else
	{
		/* Fork failed */
		perror("fork");
		free(path);
		return (1);
	}


	/* pid < 0 (fork failed) */
	perror("fork");
	return (1);
	0f7de9f (mensaje)
}
