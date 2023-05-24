#include "main.h"

/**
 * handle_input - Handles the input and executes the appropriate actions
 * @buff: Pointer to the buffer storing the input
 * @env: Pointer to the environment variables
 */
void handle_input(char *buff, char **env)
{
	char *token, **arr;
	int i = 0;
	pid_t pid = 0;

	arr = malloc(sizeof(char *) * 1024);
	token = strtok(buff, " \n\t");

	while (token)
	{
		arr[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	arr[i] = NULL;

	if (arr[0] == NULL)
	{
		free(arr);
		return;
	}

	if (_strcmp(arr[0], "env") == 0)
		print_environment(env);
	else if (_strcmp(arr[0], "exit") == 0)
	{
		free(arr);
		free(buff);
		exit_shell();
	}
	else
		execute_command(arr, pid);

	free(arr);
	free(buff);
}

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
	char *buff = NULL, **env = environ;
	size_t buff_size = 0;

	while (1)
	{
		write(1, "$ ", 2);

		if (_getline(&buff, &buff_size, stdin) == -1)
		{
			return(-1);
		}

		handle_input(buff, env);

		buff = NULL;
		buff_size = 0;
	}

	return (0);
}
