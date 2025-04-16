#include "shell.h"

/**
 * find_executable - Locates a program in PATH
 * @command: Program name
 * Return: Full path if found, NULL otherwise
 */
char *find_executable(char *command)
{
    char *path = getenv("PATH");
    char *path_copy, *dir, *full_path;

    if (!path) return NULL;

    path_copy = strdup(path);
    dir = strtok(path_copy, ":");

    while (dir) {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
