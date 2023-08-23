#include "shell.h"
#include <stdbool.h> 

typedef struct {
    const char *name;
    void (*func)(char **arv);
} Buildin;

Buildin buildin_commands[] = {
    {"exit", exitt},
    {"env", env},
    {"setenv", _setenv},
    {"unsetenv", _unsetenv},
    {NULL, NULL}
};

bool strings_equal(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return false;
        }
        s1++;
        s2++;
    }
    return (*s1 == *s2);
}

void (*checkbuild(char **arv))(char **arv) {
    int i;
    for (i = 0; buildin_commands[i].name; i++) {
        if (strings_equal(buildin_commands[i].name, arv[0])) {
            return buildin_commands[i].func;
        }
    }
    return NULL;
}
