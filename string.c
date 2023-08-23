#include "shell.h"

char *_strdup(char *str)
{
    int i, l;
    char *new;

    if (!str)
        return (NULL);

    for (l = 0; str[l] != '\0';)
    {
        l++;
    }

    new = malloc(sizeof(char) * l + 1);
    if (!new)
        return (NULL);

    for (i = 0; i < l; i++)
    {
        new[i] = str[i];
    }
    new[l] = str[l];
    return (new);
}

char *concat_all(char *name, char *sep, char *value)
{
    char *result;
    int l1, l2, l3, i, k;

    l1 = _strlen(name);
    l2 = _strlen(sep);
    l3 = _strlen(value);

    result = malloc(l1 + l2 + l3 + 1);
    if (!result)
        return (NULL);

    for (i = 0; name[i]; i++)
        result[i] = name[i];
    k = i;

    for (i = 0; sep[i]; i++)
        result[k + i] = sep[i];
    k = k + i;

    for (i = 0; value[i]; i++)
        result[k + i] = value[i];
    k = k + i;

    result[k] = '\0';

    return (result);
}

int _strlen(char *s)
{
    int i = 0;

    while (*(s + i) != '\0')
    {
        i++;
    }
    return (i);
}

int _putchar(char c)
{
    return (write(1, &c, 1));
}

void _puts(char *str)
{
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
}
