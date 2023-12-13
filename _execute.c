#include "shell.h"
/**
 * _execute - Execute command
 *
 * @command: command to execute
 * @argv: args vector
 *
 * Return: status
 */
int _execute(char **command, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			free2Darray(command);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free2Darray(command);
	}
	return (WEXITSTATUS(status));
}
