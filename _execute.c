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
	char *full_cmd;
	pid_t pid;
	int status;

	full_cmd = _getpath(command[0]);
	if(!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		free2Darray(command);
		return(127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free2Darray(command);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free2Darray(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
