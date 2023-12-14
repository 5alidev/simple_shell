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
/**
 * printError - print error message
 *
 * @name: name
 * @cmd: wrong command
 * @idx: index of error
 *
 * Return: Nothing (void)
 */
void printError(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}
/**
 * _itoa - convert integer to ASCI
 *
 * @nb: integer to convert
 *
 * Return: asci code of integer
 */
char *_itoa(int nb)
{
	char buffer[20];
	int i = 0;

	if (nb == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (nb > 0)
		{
			buffer[i++] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	buffer[i] = '\0';
	reverseString(buffer, i);

	return (_strdup(buffer));
}
/**
 * reverseString - reverse a string
 *
 * @str: string to reverse
 * @len: length of the string
 *
 * Return: Nothing (void)
 */
void reverseString(char *str, int len)
{
	char temp;
	int beg = 0;
	int end = len - 1;

	while (beg < end)
	{
		temp = str[beg];
		str[beg] = str[end];
		str[end] = temp;
		beg++;
		end--;
	}
}
