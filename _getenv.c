#include "shell.h"
/**
 * _getenv - get env variables
 *
 * @name: name of var to get
 *
 * Return: int
 */
char *_getenv(char *name)
{
	char *tptmp, *tpkey, *tpvalue, *tpenv;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tptmp =  _strdup(environ[i]);
		tpkey = strtok(tptmp, "=");
		if (_strcmp(tpkey, name) == 0)
		{
			tpvalue = strtok(NULL, "\n");
			tpenv = _strdup(tpvalue);
			free(tptmp);
			return (tpenv);
		}
		free(tptmp), tptmp = NULL;
	}
	return (NULL);
}
