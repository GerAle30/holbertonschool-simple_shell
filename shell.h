#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

/* Constants */
#define MAX_ARGS 64         // Max command arguments
#define TOKEN_DELIM " \t\n" // Characters that separate command parts

/* Global Variables */
extern char **environ;      // Environment variables
extern int exit_status;     // Tracks exit codes

/* Function Declarations */

// Core Shell Functions
void print_prompt(void);
char **parse_input(char *line);
int execute_command(char **args, char *shell_name, int line_number);

// Built-in Commands
int shell_exit(char **args, char *shell_name, int line_number);
int shell_env(char **args);
int shell_cd(char **args, char *shell_name, int line_number);

// PATH Handling
char *find_executable(char *command);

// Helper Functions
void handle_sigint(int sig);

#endif
