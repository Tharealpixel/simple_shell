#include "main.h"

/**
 * print_environment - Prints the current environment variables
 *
 * Description: Retrieves and prints the current environment variables
 *              to the standard output.
 */
void print_environment(void)
{
    int i;
    extern char **environ;

    for (i = 0; environ[i] != NULL; i++)
    {
        _puts(environ[i]);
        _putchar('\n');
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
    exit(EXIT_SUCCESS);
}
