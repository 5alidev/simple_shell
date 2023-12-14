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
char *_getenv(char *name);
char *_path(char *command);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, int *status);
void print_env(char **command, int *status);
void printError(char *name, char *cmd, int idx);
void reverseString(char *str, int len);
char *_itoa(int nb);
#endif /* SHELL_H */
