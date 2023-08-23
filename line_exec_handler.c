#include "header.h"

/**
 * split_string - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **split_string(char *str, const char *delim)
{
int wn = 0;
char **array = NULL;
char *p = str;
char *start;
int i;

while (*p)
{
while (*p && strchr(delim, *p))
{
p++;
}
if (*p)
{
start = p;
while (*p && !strchr(delim, *p))
{
p++;
}
*p = '\0';
array = realloc(array, sizeof(char *) * (wn + 1));
if (array == NULL)
{
perror(_getenv("_"));
return (NULL);
}
array[wn] = strdup(start);
if (array[wn] == NULL)
{
perror(_getenv("_"));
return (NULL);
}
wn++;
p++;
}
}
array = realloc(array, sizeof(char *) * (wn + 1));
if (array == NULL)
{
perror(_getenv("_"));
return (NULL);
}
array[wn] = NULL;
/* Free all memory allocated by the function */
for (i = 0; i < wn; i++) {
{
free(array[i]);
}
}
free(array);
return (NULL);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */
void execute(char **argv)
{
pid_t pid;
int status;

if (argv == NULL || argv[0] == NULL)
{
return;
}

pid = fork();
if (pid == -1)
{
perror(_getenv("_"));
return;
}

if (pid == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
else
{
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
}
}
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr, *old_ptr;
unsigned int i;

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
{
return (malloc(new_size));
}
if (new_size == old_size)
{
return (ptr);
}
new_ptr = malloc(new_size);
if (new_ptr == NULL)
{
return (NULL);
}
old_ptr = ptr;
for (i = 0; i < old_size && i < new_size; i++)
{
new_ptr[i] = old_ptr[i];
}
free(ptr);
return (new_ptr);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */
void freearv(char **arv)
{
int i;

for (i = 0; arv[i]; i++)
{
free(arv[i]);
}
free(arv);
}
