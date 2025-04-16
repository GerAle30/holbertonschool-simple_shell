#include "shell.h"

int exit_status; // Tracks last command's exit code

/**
 * main - Starts the shell
 * @argc: Argument count (unused)
 * @argv: Argument list (shell name)
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;    // Stores user input
	size_t len = 0;       // Tracks input size
	int line_number = 1;  // For error messages
	int is_terminal = isatty(STDIN_FILENO); // Check if interactive

	signal(SIGINT, handle_sigint); // Handle Ctrl+C

	while (1) {
		// Show prompt only in interactive mode
		if (is_terminal)
			printf("$ ");

		// Read user input
		if (getline(&line, &len, stdin) == -1)
			break; // Exit on EOF (Ctrl+D)

		// Split input into command parts
		char **args = parse_input(line);

		if (args[0]) {
			execute_command(args, argv[0], line_number);
			if (!is_terminal) line_number++;
		}

		free(args); // Clean up
	}

	free(line);
	return (exit_status);
}
