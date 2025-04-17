#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define MAX_PATH_LEN 1024
#define PROMPT "#cisfun$ "


/* Helper Functions */
int _strlen(const char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

/* Core Functions */
void display_prompt(void);
char *find_path(const char *command);
char **parse_input(char *input);
int execute_command(char **args, char *shell_name, int line_num);
int handle_builtins(char **args);

#endif
