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
}

/**
 * main - Entry point of the shell program
 *
 * Description: Reads input commands from the user or standard input,
 *              executes them, and provides a command-line interface.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buff = NULL, **env = environ;
	size_t buff_size = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "($) ", 4);
		while ((read = _getline(&buff, &buff_size, stdin)) != -1)
		{
			buff[read - 1] = '\0';
			handle_input(buff, env);
			write(STDOUT_FILENO, "($) ", 4);
		}
	}
	else
	{
		while ((read = _getline(&buff, &buff_size, stdin)) != -1)
		{
			buff[read - 1] = '\0';
			handle_input(buff, env);
		}
	}

	free(buff);
	return 0;
}
