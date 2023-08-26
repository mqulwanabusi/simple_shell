#include "shell.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
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

/**
  * _isatty - verif if terminal
  */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
    ssize_t input_length = 0;
    char *input_buffer = NULL, *path_value, *executable_path, **arguments;
    size_t buffer_size = 0;
    list_path *path_list = NULL;
    void (*command_function)(char **);

    signal(SIGINT, sig_handler);

    while (input_length != EOF)
    {
        _isatty();
        input_length = getline(&input_buffer, &buffer_size, stdin);
        _EOF(input_length, input_buffer);
        arguments = splitstring(input_buffer, " \n");
        
        if (!arguments || !arguments[0])
        {
            execute(arguments);
        }
        else
        {
            path_value = _getenv("PATH");
            path_list = linkpath(path_value);
            executable_path = _which(arguments[0], path_list);
            command_function = checkbuild(arguments);
            
            if (command_function)
            {
                free(input_buffer);
                command_function(arguments);
            }
            else if (!executable_path)
            {
                execute(arguments);
            }
            else if (executable_path)
            {
                free(arguments[0]);
                arguments[0] = executable_path;
                execute(arguments);
            }
        }
    }
    
    free_list(path_list);
    freearv(arguments);
    free(input_buffer);

    return 0;
}
