#include "shell.h"

int shell_cd(char **args, char *shell_name, int line_num)
{
	char *dir = args[1] ? args[1] : getenv("HOME");

	if (!dir) {
		fprintf(stderr, "%s: %d: cd: HOME not set\n", shell_name, line_num);
		return (1);
	}

	if (chdir(dir) == -1) {
		fprintf(stderr, "%s: %d: cd: can't cd to %s\n", 
				shell_name, line_num, dir);
		return (1);
	}
	return (0);
}
