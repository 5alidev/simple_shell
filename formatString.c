#include "shell.h"
/**
 * formatString - Format the user input
 *
 * @line: user command line
 *
 * Return: formated string (2D array)
 */
char **formatString(char *line)
{
	char *token = NULL;
	char **cmd = NULL;
	int count = 0;
	char delim[] = " \t\n";
	char *tmp = NULL;
	int i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp);
	tmp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, delim);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(line);
	line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
