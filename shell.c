#include "main.h"

/**
 * main - Entry point of the shell program
 *
 * Description: Reads input commands from the user, executes them,
 *              and provides a command-line interface.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buff = NULL;
	size_t buff_size = 0;
	char *token, **arr;
	int i = 0;

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

		if (_strcmp(arr[0], "env") == 0)
		{
			print_environment();
		}
		else if (_strcmp(arr[0], "exit") == 0)
		{
			exit_shell();
		}
		else
		{
			execute_command(arr);
		}

		i = 0;
		free(arr);
	}

	return (0);
}
