#include "main.h"

int main()
{
	char *buff = NULL;
	size_t buff_size = 0;
	char *token, **arr;
	int status, i = 0, counter;
	pid_t pid;

	extern char **environ;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		_getline(&buff, &buff_size, stdin);
		arr = malloc(sizeof(char *) * 1024);
		token = strtok(buff, " \n\t");
		while (token)
		{
			arr[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		arr[i] = NULL;

		if (_strcmp(arr[0], "exit") == 0)
		{
			free(buff);
			free(arr);
			exit(0);
		}
		else if (_strcmp(arr[0], "env") == 0)
		{
			counter = 0;
			while (environ[counter] != NULL)
			{
				write(1, environ[counter], strlen(environ[counter]));
				write(1, "\n", 1);
				counter++;
			}
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				if (execvp(arr[0], arr) == -1)
				{
					perror("execvp");
					exit(0);
				}
			}
			else
			{
				wait(&status);
			}
		}

		i = 0;
		free(arr);
	}
	return (0);
}
