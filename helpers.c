#include "shell.h"

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
			return (_strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

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
			return (full_path);
		}

		full_path[0] = '\0';
		dir = strtok(NULL, ":");
	}

	free(full_path);
	free(path);
	return (NULL);
}

