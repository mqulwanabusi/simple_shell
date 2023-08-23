#include "header.h"

/**
 * exit_shell - exits the shell with or without a return of status n
 * @args: array of words of the entered line
 */

void exit_shell(char **args)
{
int exit_code = EXIT_SUCCESS;
if (args[1])
{
exit_code = (_atoi(args[1]) <= -1) ? EXIT_FAILURE : _atoi(args[1]);
freearv(args);
exit(exit_code);
}
freearv(args);
exit(EXIT_SUCCESS);
}
