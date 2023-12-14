#include "shell.h"
/**
 * _execute - Execute command
 *
 * @command: command to execute
 * @argv: args vector
 *
 * Return: status
 */
int _execute(char **command, char **argv, int idx)
{
	char *fullCmd;
	pid_t pid;
	int status;

	fullCmd = _path(command[0]);
	if (!fullCmd)
	{
		printError(argv[0], command[0], idx);
		free2Darray(command);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(fullCmd, command, environ) == -1)
		{
			free(fullCmd), fullCmd = NULL;
			free2Darray(command);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free2Darray(command);
		free(fullCmd), fullCmd = NULL;
	}
	return (WEXITSTATUS(status));
}
