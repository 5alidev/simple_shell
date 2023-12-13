#include "shell.h"
/**
 * _strdup - duplicate a string
 *
 * @str: pointer to string to duplicate
 *
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int i, len;
	char *newStr;

	if (!str)
	{
		return (NULL);
	}
	for (len = 0; str[len] != '\0';)
	{
		len++;
	}
	newStr = malloc(sizeof(char) * len + 1);
	if (!newStr)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		newStr[i] = str[i];
	}
	newStr[len] = str[len];
	return (newStr);
}
