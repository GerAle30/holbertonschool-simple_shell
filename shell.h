#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define TOKEN_DELIM " \t\r\n\a"

/* Declare environ explicitly for C89 */
extern char **environ;

/* Function prototypes */
void handle_sigint(int sig);
char **parse_input(char *line);
int execute_command(char **args, char *shell_name, int line_num);
int shell_exit(char **args, char *shell_name, int line_num);
int shell_env(char **args);
int shell_cd(char **args, char *shell_name, int line_num);

/* Add these prototypes */
void display_prompt(void);
size_t _strlen(const char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int handle_builtins(char **args);

#endif
