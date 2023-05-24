#include "main.h"

/**
 * print_environment - Prints the current environment variables
 * @env : enviroment
 * Description: Retrieves and prints the current environment variables
 *              to the standard output.
 */
void print_environment(char **env)
{
	int counter = 0;
	int strlm =  _strlen(env[counter]);

	while (env[counter] != NULL)
	{
		write(1, env[counter], strlm);
		write(1, "\n", 1);
		counter++;
	}
}

/**
 * exit_shell - Exits the shell program
 *
 * Description: Frees allocated memory, performs any necessary cleanup,
 *              and terminates the shell program.
 */
void exit_shell(void)
{
	exit(0);
}
/**
 * execute_command - Executes a command in the shell.
 * @arr: The command to execute.
 * @pid: child process
 * Return: void
 */
void execute_command(char **arr, pid_t pid)
{
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(arr[0], arr) == -1)
		{
			perror("execvp");
			exit(1);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(1);
		}
	}
}
