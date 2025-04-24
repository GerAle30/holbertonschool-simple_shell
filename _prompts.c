#include "shell.h"
#include <unistd.h>

/**
 * print_prompt - Writes the shell prompt if running.
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}
