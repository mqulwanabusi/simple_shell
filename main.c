#include "header.h"
/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sign_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		HANDLE_END_OF_FILE(len, buff);
		arv = split_string(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
