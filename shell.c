#include "shell.h"
/**
 * parse_input - Parse input
 *
 * @ptLine: line
 *
 * Return: Array (formated input)
 */
char **parse_input(char *ptLine)
{
	char *command = strtok(ptLine, " \t\n");
	char **array = NULL;
	char *next_word = NULL;

	if (command != NULL)
	{
		array = malloc(sizeof(char *) * 2);
		if (array != NULL)
		{
			array[0] = _strdup(command);
			array[1] = NULL;
			next_word = strtok(NULL, " \t\n");
			if (next_word != NULL)
			{
				printf("No such file or directory\n");
				free(array[0]);
				free(array);
				return (NULL);
			}
		}
		else
		{
			perror("Memory Alloc");
			return (NULL);
		}
	}
	else
	{
		printf("No Command Found\n");
	}
	return (array);
}
/**
 * execute_command - Execute Command
 *
 * @array: command to execute
 * @env: environment variables
 *
 * Return: Nothing (void)
 */
void execute_command(char **array, char **env)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(array[0], array, env) == -1)
		{
			printf("No such file or directory\n");
		}
	}
	else
	{
		wait(&status);
	}
}
/**
 * main - simple shell
 *
 * @argc: arg count
 * @argv: arg vector
 * @env: environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv, char **env)
{
	char *ptLine = NULL;
	size_t len = 0;
	int nbr_chars;
	char **array;

	(void)argc;
	(void)argv;
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		nbr_chars = getline(&ptLine, &len, stdin);
		if (nbr_chars == -1)
		{
			if (feof(stdin))
				break;
		}
		array = parse_input(ptLine);
		if (array == NULL)
		{
			free(ptLine);
			continue;
		}
		execute_command(array, env);
		free(array[0]);
		free(array);
	}
	free(ptLine);
	return (0);
}
