#include "header.h"

/**
* HANDLE_END_OF_FILE - handles the End of File
* @len: return value of getline function
* @buff: buffer
*/

void HANDLE_END_OF_FILE(int len, char *buff)
{
(void)buff;
if (len == -1)
{
if (isatty(STDIN_FILENO))
{
_puts("\n");
free(buff);
}
exit(0);
}
}
