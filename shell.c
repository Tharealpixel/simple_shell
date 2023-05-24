#include "main.h"
#include <ctype.h>

/**
 * main - Entry point of the shell program
 *
 * Description: Reads input commands from the user, executes them,
 *              and provides a command-line interface.
 *
 * Return: Always 0.
 */

#include "main.h"
#include <ctype.h>

/**
 * execute_shell - Execute the shell program
 */
int main(void)
{
	char *buff = NULL, **arr, **env = environ;
	size_t buff_size = 0;
	pid_t pid = 0;

	while (1)
	{
		if (!read_command(&buff, &buff_size))
			continue;

		arr = malloc(sizeof(char *) * 1024);

		parse_arguments(buff, arr);

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
		buff = NULL;
		buff_size = 0;
	}
}

/**
 * parse_arguments - Parse the command line arguments
 * @buff: Pointer to the buffer storing the command line input
 * @arr: Double pointer to store the parsed arguments
 *
 * Return: Number of arguments parsed
 */
int parse_arguments(char *buff, char **arr)
{
	int i = 0;
	char *token = strtok(buff, " \n\t");

	while (token)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n\t");
	}

	arr[i] = NULL;

	return (i);
}

/**
 * read_command - Read command input from the user
 * @buff: Pointer to the buffer storing the input line
 * @buff_size: Pointer to the size of the buffer
 *
 * Return: 1 if successful, 0 otherwise
 */
int read_command(char **buff, size_t *buff_size)
{
	char *trimmed_buff;

	write(1, "$ ", 2);
	if (_getline(buff, buff_size, stdin) == -1)
	{
		perror("getline");
		exit(1);
	}

	trimmed_buff = *buff;
	while (isspace(*trimmed_buff))
		trimmed_buff++;

	if (*trimmed_buff == '\0')
	{
		free(*buff);
		return (0);
	}

	return (1);
}

