#include "shell.h"
/**
 * free2Darray - Free an array of 2D
 *
 * @array: array to be free
 *
 * Return: Nothing (void)
 */
void free2Darray(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]), array[i] = NULL;
	free(array), array = NULL;
}
