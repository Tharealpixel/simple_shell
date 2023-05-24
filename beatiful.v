#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main -Simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *buff;
	char *token;
	char *arg[10];
	int j;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILUR);
	}

	while (1)
	{
		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);

		token = strtok(buffer, " \n");
		j = 0;
		while (token != NULL)
		{
			arg[j++] = token;
			token = strtok(Null, "\n");
		}
		arg[i] = NULL;

		if (strcmp(arg[0], "exit") == 0)
			break;
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(arg[0], arg) == -1)
			{
				perror("execvp error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(buff);
	return (0);
}
