#include "shell.h"
/**
 * getCommand - get the command line
 *
 * Return: string line
 */
char *getCommand(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nbr_chars = 0;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	nbr_chars = getline(&line, &len, stdin);
	if (nbr_chars == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
