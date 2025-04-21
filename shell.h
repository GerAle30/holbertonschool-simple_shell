#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

/*Global environ variable */
extern char **environ;

/* Function prototypes */
char **parse_line(char *line);
void free_args(char **args);
int handle_builtin(char **args, char *line);
void print_env(void);
void execute_command(char **args, char *program_name);

#endif /* SHELL_H */

