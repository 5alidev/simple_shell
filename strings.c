#include "shell.h"
/**
 * _strdup - duplicate a string
 *
 * @str: pointer to string to duplicate
 *
 * Return: pointer to a string
 */
char *_strdup(const char *str)
{
	char *newStr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	newStr = malloc(sizeof(char) * (len + 1));
	if (newStr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		newStr[i] = str[i];
	return (newStr);
}
/**
 * _strcmp - compare two strings
 *
 * @s1: first string
 * @s2: seconde string
 *
 * Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
	int compare;

	compare = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		compare = (int)*s1 - (int)*s2;
	}
	return (compare);
}
/**
 * _strlen - length of a string
 *
 * @str: string
 *
 * Return: Integer (length)
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcat - concat two strings
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: String
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = *src;
	return (dest);
}
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
