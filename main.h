#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*extern variables*/
extern char **environ;

/*functions to make the code look harder*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*Memory functions*/
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t new_size);

/*BUILD*/
void exit_shell(void);
void print_environment(char **env);
void execute_command(char **arr, pid_t pid);
void handle_input(char *buff, char **env);

/*Helpers*/
void _puts(char *str);
int _putchar(char c);

/*str*/
int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strspn(const char *str, const char *charset);

/*enveronment*/
int _menver(info_t *info);
char *_getenver(info_t, const char *nm);
int _msetenver(info_t *info);
int _insetenver(info_t *info);
int _enver_list(info_t *info);

#endif
