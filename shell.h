#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
extern char **environ;
int _execute(char **command, char **argv, int idx);
void free2Darray(char **array);
char *getCommand(void);
char **formatString(char *line);
int _getenv(const char *var);
char *_path(char *command);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void print_error(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);
char *_itoa(int n);
#endif /* SHELL_H */
