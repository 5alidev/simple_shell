#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	char *ptLine = NULL;
	size_t len = 0;
	int nbr_chars;
	char *command = NULL;
	int i = 0, status;
	pid_t pid;
	char **array = NULL;
	extern char **environ;

	while (1)
	{
		array = malloc(sizeof(char *) * 1024);
		write(1, "#cisfun$ ",9); /* write 9 chars*/
		nbr_chars = getline(&ptLine, &len, stdin);
		command = strtok(ptLine," \t\n");
		while(command)
		{
			array[i] = command;
			command = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(array[0], array, environ) == -1)
				printf("No such file or directory\n");
		}
		else
			wait(&status);
		i = 0;
		free(array);

	}
	return (0);
}
