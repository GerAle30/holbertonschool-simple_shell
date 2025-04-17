#include "shell.h"

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
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			fprintf(stderr, "%s: %d: %s: not found\n",
					shell_name, line_num, args[0]);
			exit(EXIT_FAILURE);
		}
	} else if (pid > 0) {
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return WEXITSTATUS(status);
		return (1);
	} else {
		perror("fork");
		return (1);
	}
}
