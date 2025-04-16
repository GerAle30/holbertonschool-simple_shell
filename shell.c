#include "shell.h"

/**
 * main - Simple shell entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
    char input[MAX_INPUT];
    char **args;
    ssize_t read_size;
    int status = 1;

    (void)argc;

    while (status)
    {
        display_prompt();

        read_size = read(STDIN_FILENO, input, MAX_INPUT);
        if (read_size == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        else if (read_size == 0)
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        input[read_size] = '\0';
        if (_strlen(input) == 0)
            continue;

        args = parse_input(input);
        status = execute_command(args, argv[0]);
        free(args);
    }

    return EXIT_SUCCESS;
}

/**
 * display_prompt - Displays shell prompt
 */
void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        printf(PROMPT);
    fflush(stdout);
}

/**
 * find_path - Finds command in PATH
 * @command: Command to find
 * Return: Full path if found, NULL otherwise
 */
char *find_path(const char *command)
{
    char *path, *dir, *full_path;
    struct stat st;

    if (!command)
        return NULL;

    /* Check if command has path (/, ./) */
    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &st) == 0)
            return _strdup(command);
        return NULL;
    }

    path = getenv("PATH");
    if (!path)
        return NULL;

    path = _strdup(path);
    dir = strtok(path, ":");
    full_path = malloc(MAX_PATH_LEN);

    while (dir)
    {
        _strcat(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, command);

        if (stat(full_path, &st) == 0)
        {
            free(path);
            return full_path;
        }

        full_path[0] = '\0';
        dir = strtok(NULL, ":");
    }

    free(full_path);
    free(path);
    return NULL;
}

/**
 * execute_command - Executes a command
 * @args: Command arguments
 * @shell_name: Shell name for errors
 * Return: 1 to continue, 0 to exit
 */
int execute_command(char **args, char *shell_name)
{
    pid_t pid;
    char *path;
    int status;

    if (!args || !args[0])
        return 1;

    /* Handle built-in commands */
    if (handle_builtins(args) == 0)
        return 0;

    path = find_path(args[0]);
    if (!path)
    {
        fprintf(stderr, "%s: 1: %s: not found\n", shell_name, args[0]);
        return 1;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(path);
        return 1;
    }

    if (pid == 0)
    {
        if (execve(path, args, environ) == -1)
        {
            perror(shell_name);
            free(path);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        free(path);
    }

    return 1;
}

/**
 * handle_builtins - Handles built-in commands
 * @args: Command arguments
 * Return: 1 if not builtin, 0 if exit
 */
int handle_builtins(char **args)
{
    if (_strcmp(args[0], "exit") == 0)
        return 0;

    if (_strcmp(args[0], "env") == 0)
    {
        char **env = environ;
        while (*env)
            printf("%s\n", *env++);
        return 1;
    }

    return -1;
}
