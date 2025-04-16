#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Displays the shell prompt.
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - Executes a single command.
 * @command: The command to execute.
 * @shell_name: Name of the shell for error messages.
 * Return: void
 */
void execute_command(char *command, char *shell_name)
{
	pid_t pid;
	char *args[] = {command, NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(command, args, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", shell_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

/**
 * main - Entry point for the simple shell.
 * @argc: Argument count (unused).
 * @argv: Argument vector.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t read_size;

	(void)argc; /* Unused parameter */

	while (1)
	{
		display_prompt();

		read_size = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
		if (read_size == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
		{
			/* Handle Ctrl+D (EOF) */
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* Remove newline character */
		if (command[read_size - 1] == '\n')
			command[read_size - 1] = '\0';
		else
			command[read_size] = '\0';

		/* Skip empty commands */
		if (strlen(command) == 0)
			continue;

		execute_command(command, argv[0]);
	}

	return (EXIT_SUCCESS);
}
