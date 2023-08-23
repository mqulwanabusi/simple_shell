#include "header.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
ii * Return: pointer to a string
 */
char *_strdup(char *str)
{
int len;
char *new;

if (!str)
{
return (NULL);
}
len = strlen(str) + 1;
new = malloc(len *sizeof(char));
if (!new)
{
return (NULL);
}
memcpy(new, str, len);
return (new);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
char *result;
int total_len = _strlen(name) + _strlen(sep) + _strlen(value) + 1;

result = malloc(total_len);
if (!result)
{
return (NULL);
}
sprintf(result, "%s%s%s", name, sep, value);
return (result);
}

/**
 * _puts - prints a string
 * @str: pointer to string
 */

void _puts(char *str)
{
int i = 0;

while (str[i])
{
_putchar(str[i]);
i++;
}
}


/**
 * _strlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int _strlen(char *s)
{
int i = 0;

while (*(s + i) != '\0')
{
i++;
}
return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(2, &c, 1));
}
