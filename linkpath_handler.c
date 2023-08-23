#include "header.h"


/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
int len, i;

if (!name || !environ)
{
return (NULL);
}
len = strlen(name);
for (i = 0; environ[i]; i++)
{
if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
return (&(environ[i][len + 1]));
}
}
return (NULL);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */
list_path *add_node_end(list_path **head, char *str)
{
list_path *new, *temp;

if (!head || !str)
{
return (NULL);
}
new = malloc(sizeof(list_path));
if (!new)
{
return (NULL);
}
new->dir = _strdup(str);
if (!new->dir)
{
free(new);
return (NULL);
}
new->p = NULL;
if (!*head)
{
*head = new;
return (*head);
}
temp = *head;
while (temp->p)
{
temp = temp->p;
}
temp->p = new;
return (new);
}


/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
list_path *head = NULL;
list_path *current = NULL;
char *token;
char *cpath = _strdup(path);
char *p = cpath;

while (*p != '\0')
{
token = p;
while (*p != ':' && *p != '\0')
p++;

if (*p == ':')
{
*p++ = '\0';
}
current = malloc(sizeof(list_path));
if (current == NULL)
{
free_list(head);
return (NULL);
}
current->dir = _strdup(token);
current->p = NULL;
if (head == NULL)
{
head = current;
}
else
{
list_path *tmp = head;
while (tmp->p)
{
tmp = tmp->p;
}
tmp->p = current;
}
}
free(cpath);
return (head);
}

/**
 * _which - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
struct stat st;
char *string = NULL;
list_path *tmp = head;

while (tmp)
{
int len = _strlen(tmp->dir) + _strlen(filename) + 2;
string = malloc(sizeof(char) * len);
if (!string)
{
perror("malloc failed");
exit(EXIT_FAILURE);
}
strcpy(string, tmp->dir);
strcat(string, "/");
strcat(string, filename);
if (stat(string, &st) == 0)
{
return (string);
}
free(string);
tmp = tmp->p;
}
return (NULL);
}

/**
 * free_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_list(list_path *head)
{
list_path *storage;

while (head)
{
storage = head->p;
free(head->dir);
free(head);
head = storage;
}
}
