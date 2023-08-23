#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

/* buildin.c */
void exitt(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
int _atoi(char *s);
void env(char **arv);

/* string.c */
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);

/* linkpath.c */
char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);
void free_list(list_path *head);

/* line_exec.c */
char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearv(char **arv);

/* checkbuild.c */
void(*checkbuild(char **arv))(char **arv);

#endif
