#include "shell.h"

/**
 * find_path - Busca el valor de PATH sin usar getenv
 * Return: una copia del contenido de PATH, o NULL si no existe
 */
char *find_path(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			return (_strdup(environ[i] + 5));
	}
	return (NULL);
}

/**
 * execute_command - Ejecuta un comando si existe
 * @args: lista de argumentos
 * @prog: nombre del programa (para mensajes de error)
 * @exit_status: puntero al status de salida
 */
void execute_command(char **args, char *prog, int *exit_status)
{
	char *cmd = NULL, *path_value, *path_token, *full_path;
	int found = 0;
	pid_t pid;
	int status;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], X_OK) == 0)
			cmd = _strdup(args[0]);
	}
	else
	{
		path_value = find_path();
		if (path_value)
		{
			path_token = strtok(path_value, ":");
			while (path_token)
			{
				full_path = malloc(_strlen(path_token) + _strlen(args[0]) + 2);
				if (!full_path)
				{
					free(path_value);
					return;
				}
				_strcpy(full_path, path_token);
				_strcat(full_path, "/");
				_strcat(full_path, args[0]);

				if (access(full_path, X_OK) == 0)
				{
					cmd = full_path;
					found = 1;
					break;
				}
				free(full_path);
				path_token = strtok(NULL, ":");
			}
			free(path_value);
		}
	}

	if (!cmd)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog, args[0]);
		*exit_status = 127;
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			*exit_status = WEXITSTATUS(status);
	}

	if (!found && cmd)
		free(cmd);
}

