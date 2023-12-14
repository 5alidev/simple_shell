#include "shell.h"
/**
 * main - program that adds positive numbers.
 *
 * @argc: arg count (number of args)
 * @argv: arg vector (string table)
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *inputLine = NULL;
	char **command = NULL;
	int status = 0;
	int idx = 0;
	(void) argc;

	while (1)
	{
		inputLine = getCommand();
		if (inputLine == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = formatString(inputLine);
		if (!command)
			continue;
		if (is_builtin(command[0]))
		{
			handle_builtin(command, argv, &status, idx);
		}
		status = _execute(command, argv, idx);
	}
	return (0);
}
