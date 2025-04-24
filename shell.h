#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
/*Global environ variable */
extern char **environ;

/* Function prototypes */
char **parse_line(char *line);
void free_args(char **args);
int handle_builtin(char **args, char *line);
void print_env(void);
void execute_command(char **args, char *prog, int *exit_status);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /* SHELL_H */

