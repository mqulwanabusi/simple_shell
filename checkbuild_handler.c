#include "header.h"

/**
* checkbuild - checks if the command is a built-in
* @args: array of arguments
* Return: pointer to function that takes args and returns void
*/
void (*checkbuild(char **args))(char **args)
{
int i, j;

/**
* struct builtins - Structure for defining built-in shell commands
* @name: name of the built-in command
* @func: pointer to function that executes the command
* This struct is used to define the built-in commands for a shell program.
* It contains the name of the command and a pointer to the function
* that executes the command.
*/
struct builtins
{
char *name;
void (*func)(char **args);
} builtins[] = {
{"exit", exit_shell},
{"env", env},
{"setenv", _setenv},
{"unsetenv", _unsetenv},
{NULL, NULL}
};

for (i = 0; builtins[i].name != NULL; i++)
{
j = 0;
while (builtins[i].name[j] == args[0][j])
{
if (builtins[i].name[j] == '\0' && args[0][j] == '\0')
return (builtins[i].func);
j++;
}
}
return (NULL);
}
