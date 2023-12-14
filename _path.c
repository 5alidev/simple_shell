#include "shell.h"
/**
 * _path - handle PATH
 *
 * @command: command to check
 *
 * Return: path
 */
char *_path(char *command)
{
	char *pathEnv, *fullCmd, *pathDir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	pathEnv = _getenv("PATH");
	if (!pathEnv)
		return (NULL);
	pathDir = strtok(pathEnv, ":");
	while (pathDir)
	{
		fullCmd = malloc(_strlen(pathDir) + _strlen(command) + 2);
		if (fullCmd)
		{
			_strcpy(fullCmd, pathDir);
			_strcat(fullCmd, "/");
			_strcat(fullCmd, command);
			if (stat(fullCmd, &st) == 0)
			{
				free(pathEnv);
				return (fullCmd);
			}
			free(fullCmd), fullCmd = NULL;
			pathDir = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
