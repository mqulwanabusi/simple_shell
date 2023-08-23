#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

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

/*Shell starting function*/
void _isatty(void);
void HANDLE_END_OF_FILE(int len, char *buff);
void sign_handler(int sig_num);

/* string_handler.c */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

/* line_exec_handler.c */
char **split_string(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearv(char **arv);

/* linkpath_handler.c */
char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);
void free_list(list_path *head);

/* checkbuild_handler.c */
void(*checkbuild(char **arv))(char **arv);

/* buildin_handler.c */
void exit_shell(char **args);
int _atoi(const char *s);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

extern char **environ;

#endif
