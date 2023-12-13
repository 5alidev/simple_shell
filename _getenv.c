#include "shell.h"
int _getenv(const char *var)
{
	char *tptmp, *tpkey, *tpvalue, *tpenv;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tptmp =  _strdup(environ[i]);
		tpkey = strtok(tptmp, "=");
		if (_strcmp(tpkey, var) == 0)
		{
			tpvalue = strtok(NULL, "\n");
			env = _strdup(tpvalue);
			free(tptmp);
			return (tpenv);
		}
		free(tptmp), tptmp = NULL;
	}
	return (NULL);
}
