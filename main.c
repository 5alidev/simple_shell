#include <stdio.h>
#include <string.h>

int main()
{
	char *ptLine = NULL;
	size_t len;
	ssize_t checkInput;
	char *command = NULL;

	printf(">>");
	checkInput = getline(&ptLine, &len, stdin);
	command = strtok(ptLine," \t\n");

	while (command != NULL)
	{
		printf("%s\n", command);
		command = strtok(NULL, " \t\n");
	}
	return (0);
}
