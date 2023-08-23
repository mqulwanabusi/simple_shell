#include "header.h"

/**
 * _atoi - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(const char *s)
{
int index = 0, result = 0, sign = 1;

while (s[index] == ' ' || s[index] == '\t')
{
index++;
}

if (s[index] == '-')
{
sign = -1;
}
if (s[index] == '-' || s[index] == '+')
{
index++;
}
while (s[index] >= '0' && s[index] <= '9')
{
result = (result * 10) + (s[index] - '0');
index++;
}
return (result *sign);
}

/**
 * env - prints the current environment
 * @arv: array of arguments
 */
void env(char **arv __attribute__((unused)))
{
int i;

for (i = 0; environ[i]; i++)
{
_puts(environ[i]);
_puts("\n");
}
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */
void _setenv(char **arv)
{
int i;

if (!arv[1] || !arv[2])
{
perror(_getenv("_"));
return;
}
for (i = 0; environ[i]; i++)
{
if (strncmp(arv[1], environ[i], _strlen(arv[1])) == 0)
{
strcpy(environ[i], concat_all(arv[1], "=", arv[2]));
return;
}
}
environ[i] = concat_all(arv[1], "=", arv[2]);
environ[i + 1] = NULL;
}

/**
 * starts_with - check if a string starts with a given prefix
 * @str: the string to check
 * @prefix: the prefix to look for
 *
 * Return: 1 if the string starts with the prefix, 0 otherwise
 */
bool starts_with(const char *str, const char *prefix)
{
size_t prefix_len = strlen(prefix);
return (strncmp(str, prefix, prefix_len) == 0);
}

/**
 * _unsetenv - Remove an environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
int i;
char *env_var;

if (!arv[1])
{
perror(_getenv("_"));
return;
}
env_var = concat_all(arv[1], "=", NULL);
for (i = 0; environ[i]; i++)
{
if (starts_with(environ[i], env_var))
{
free(environ[i]);
while (environ[i + 1])
{
environ[i] = environ[i + 1];
i++;
}
environ[i] = NULL;
break;
}
}
free(env_var);
}
