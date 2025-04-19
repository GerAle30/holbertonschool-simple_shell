#ifndef SHELL_H
#define SHELL_H

/* Standard library includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
<<<<<<< HEAD
#include <signal.h>
=======
#include <fcntl.h>
#include <errno.h>
>>>>>>> 0f7de9f (mensaje)

/* Macro definitions */
#define MAX_ARGS 64
#define MAX_INPUT 1024
#define MAX_PATH_LEN 1024
#define TOKEN_DELIM " \t\r\n\a"

/* External variables */
extern char **environ;

<<<<<<< HEAD
/* String functions */
size_t _strlen(const char *s);
=======
/* Function prototypes */

/* Shell core functions */
void display_prompt(void);
char **parse_input(char *input);
int execute_command(char **args, char *shell_name, int line_num);
int handle_builtins(char **args);

/* Path related functions */
char *find_path(const char *command);
char *find_executable(char *command);

/* Builtin commands */
int shell_cd(char **args, char *shell_name, int line_num);
int shell_exit(char **args, char *shell_name, int line_num);
int shell_env(char **args);

/* String helper functions */
int _strlen(const char *s);
>>>>>>> 0f7de9f (mensaje)
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

<<<<<<< HEAD
/* Shell functions */
void handle_sigint(int sig);
char **parse_input(char *line);
int execute_command(char **args, char *shell_name, int line_num);
int shell_exit(char **args, char *shell_name, int line_num);
int shell_env(char **args);
int shell_cd(char **args, char *shell_name, int line_num);
void display_prompt(void);
int handle_builtins(char **args, char *shell_name, int line_num);
char *find_path(const char *command);
int execute_command(char **args, char *shell_name, int line_num);
int handle_builtins(char **args, char *shell_name, int line_num);

#endif
=======
#endif /* SHELL_H */
>>>>>>> 0f7de9f (mensaje)
