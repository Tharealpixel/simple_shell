#include "main.h"

/**
 *_menver -print function the current enbironment
 * @inf: structure potential arguments;
 *       constant function prototype.
 * Return: Always 0
 */
int _menver(inf_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenver -gets the value of an environ variable
 * @inf: strcture potentail argument
 * @nm: enver variable name
 *
 * Return: the value
 */
char *_getenv(inf_t, const char *nm)
{
	list_t *node = inf->enver;
	char *p;

	while (node)
	{
		p = start_with(node->str, nm);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _msetenver -Initialize a new environment variable,
 *	       or a exiting one
 * @info: structure argument
 * Return: Always 0
 */
int _msetenver(inf_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("number of argument\n");
		return (1);
	}
	if (_setenver(inf, inf->argv[1], inf-
