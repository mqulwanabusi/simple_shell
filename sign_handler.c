#include "header.h"

/**
 * sign_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sign_handler(int sig_num)
{
if (sig_num == SIGINT)
{
_puts("\n#cisfun$ ");
}
}
